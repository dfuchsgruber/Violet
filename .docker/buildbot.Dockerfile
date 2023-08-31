FROM gcc:12.1
CMD [ "/usr/local/bin/violet-entrypoint" ]
ENV LANG=en_US.UTF-8
ENV WORKON_HOME /venv
ENV DEVKITPRO /opt/devkitpro
ENV DEVKITARM ${DEVKITPRO}/devkitARM
ENV DEVKITPPC ${DEVKITPRO}/devkitPPC
ENV PATH ${DEVKITPRO}/tools/bin:$PATH
ENV PSG_DATA=/etc/violet/gba-mus-ripper/psg_data.raw
ENV GOLDENSUN_SYNTH=/etc/violet/gba-mus-ripper/goldensun_synth.raw

RUN apt-get update --fix-missing && \
    apt-get install -y \
        apt-transport-https \
        libgl1-mesa-dev \
        gcc-arm-none-eabi \
        bc \
        cmake \
        python3 \
        python-is-python3 \
        python3-pip \
        ssh \
        sudo \
        vim && \
    rm -rf /var/lib/apt/lists/*

RUN mkdir -p /etc/violet
WORKDIR /etc/violet

RUN \
        apt-get update && \
        mkdir -p /usr/local/share/keyring/ && \
        wget -O /usr/local/share/keyring/devkitpro-pub.gpg https://apt.devkitpro.org/devkitpro-pub.gpg && \
        echo "deb [signed-by=/usr/local/share/keyring/devkitpro-pub.gpg] https://apt.devkitpro.org stable main" > /etc/apt/sources.list.d/devkitpro.list && \
        apt-get update && \
        apt-get install -y devkitpro-pacman && \
    rm -rf /var/lib/apt/lists/* && \
    { [ -f /etc/mtab ] || hotfix=1; } && \
    { [ ! -z ${hotfix+z} ] && ln -s /proc/self/mounts /etc/mtab || true; } && \
    dkp-pacman -Syu --noconfirm gba-dev grit && \
    { [ ! -z ${hotfix+z} ] && rm /etc/mtab || true; }

RUN \
        git clone https://github.com/ipatix/wav2agb.git && \
        directory=$(pwd) && \
        cd wav2agb && \
        git checkout b461c20e1da68a95b4084456bf5fe651eb10a17f && \
        make && \
        chmod 744 wav2agb && \
        install -t /usr/local/bin ./wav2agb && \
        cd $directory && \
        unset directory

RUN \
        git clone https://github.com/pret/pokefirered.git && \
        directory=$(pwd) && \
        cd pokefirered/tools/mid2agb && \
        git checkout f484b96062f866d00c28bec5b33b032e14280ea1 && \
        make && \
        chmod 744 mid2agb && \
        install -t /usr/local/bin ./mid2agb && \
        cd $directory && \
        unset directory
RUN \
        git clone https://github.com/Kingcom/armips.git && \
        directory=$(pwd) && \
        cd armips && \
        git checkout 4f414f39aa3aaa54dd83e04b0c5f9e246d4837b4 && \
        git submodule update --init --recursive && \
        mkdir build && cd build && \
        cmake -DCMAKE_BUILD_TYPE=Release .. && \
        cmake --build . && \
        chmod 744 armips && \
        install -t /usr/local/bin ./armips && \
        cd $directory && \
        unset directory
RUN \
        git clone https://github.com/WodkaRHR/gba-mus-ripper.git && \
        directory=$(pwd) && \
        cd gba-mus-ripper && \
        git checkout 1211a9b8426fa79d2e29e394fa900c8ad56865b5 && \
        make && \
        chmod 744 ./* && \
        install -t /usr/local/bin ./out/* && \
        cd $directory && \
        unset directory
RUN \
        git clone https://github.com/ipatix/midi2agb.git && \
        directory=$(pwd) && \
        cd midi2agb && \
        git checkout ff820bf5453a0e2b6a4612da2cd1d5fc8c220b20 && \
        git submodule update --init --recursive && \
        make && \
        install -t /usr/local/bin midi2agb && \
        cd $directory && \
        unset directory

RUN \
        binName=/usr/local/bin/oh-my-posh && \
        wget https://github.com/JanDeDobbeleer/oh-my-posh/releases/download/v18.5.0/posh-linux-amd64 -O $binName && \
        chmod a+x $binName && \
        unset binName

RUN pip3 install --upgrade pip
RUN pip3 install pipenv

RUN adduser \
     --disabled-password \
     --uid 1002 \
     --home /home/violet \
     "violet"

RUN usermod -aG sudo violet
RUN echo '%sudo ALL=(ALL:ALL) NOPASSWD: ALL' > /etc/sudoers.d/violet

WORKDIR /workspace/Violet
COPY .docker/buildbot-entrypoint.sh /usr/local/bin/violet-entrypoint
RUN mkdir -p /venv || true
RUN chmod 777 /venv
USER violet

RUN curl https://pyenv.run | bash
RUN \
        echo 'export PYENV_ROOT="$HOME/.pyenv"' >> ~/.bashrc && \
        echo 'command -v pyenv >/dev/null || export PATH="$PYENV_ROOT/bin:$PATH"' >> ~/.bashrc && \
        echo 'eval "$(pyenv init -)"' >> ~/.bashrc

RUN chmod 777 /home/violet/.pyenv

RUN \
        configFile="/workspace/Violet/.devcontainer/omp.json" && \
        command="oh-my-posh init bash" && \
        echo '[ -f '"$configFile"' ] || eval "$('"$command"')"' >> ~/.bashrc && \
        echo '[ -f '"$configFile"' ] && eval "$('"$command"' --config '"$configFile"')"' >> ~/.bashrc && \
        echo 'eval "$(oh-my-posh completion bash)"' >> ~/.bashrc && \
        echo "alias ll='ls -al'" >> ~/.bashrc && \
        echo "alias la='ls -A'" >> ~/.bashrc && \
        echo "alias l='ls'" >> ~/.bashrc && \
        unset configFile && \
        unset command
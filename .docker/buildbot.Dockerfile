FROM gcc:12
CMD [ "/usr/local/bin/violet-entrypoint" ]
ENV WORKON_HOME /venv
ENV DEVKITPRO /opt/devkitpro
ENV DEVKITARM ${DEVKITPRO}/devkitARM
ENV DEVKITPPC ${DEVKITPRO}/devkitPPC
ENV PATH ${DEVKITPRO}/tools/bin:$PATH

RUN apt-get update --fix-missing && \
    apt-get install -y \
        apt-transport-https \
        libgl1-mesa-dev \
        gcc-arm-none-eabi \
        bc \
        cmake \
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
    ln -s /proc/self/mounts /etc/mtab && \
    dkp-pacman -S --noconfirm gba-dev && \
    rm /etc/mtab

RUN \
        git clone https://github.com/ipatix/wav2agb.git && \
        directory=$(pwd) && \
        cd wav2agb && \
        git checkout 8d09076bd53d32c15ef2829d157ba87556f50de0 && \
        make && \
        chmod 744 wav2agb && \
        install -t /usr/local/bin ./wav2agb && \
        cd $directory && \
        unset directory

RUN \
        git clone https://github.com/pret/pokefirered.git && \
        directory=$(pwd) && \
        cd pokefirered/tools/mid2agb && \
        git checkout 471608b56abbdf70a452896a0d895ffa5b4b06f9 && \
        make && \
        chmod 744 mid2agb && \
        install -t /usr/local/bin ./mid2agb && \
        cd $directory && \
        unset directory
RUN \
        git clone https://github.com/Kingcom/armips.git && \
        directory=$(pwd) && \
        cd armips && \
        git checkout be0124c9cb7610ecd88206f9ccbff954d6ae1897 && \
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
        wget https://github.com/JanDeDobbeleer/oh-my-posh/releases/download/v11.1.1/posh-linux-amd64 -O $binName && \
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

WORKDIR /workspace
COPY .docker/buildbot-entrypoint.sh /usr/local/bin/violet-entrypoint
RUN mkdir -p /venv || true
RUN chmod 777 /venv
USER violet

RUN \
        configFile="/workspace/.devcontainer/omp.json" && \
        command="oh-my-posh init bash" && \
        echo '[ -f '"$configFile"' ] || eval "$('"$command"')"' >> ~/.bashrc && \
        echo '[ -f '"$configFile"' ] && eval "$('"$command"' --config '"$configFile"')"' >> ~/.bashrc && \
        echo 'eval "$(oh-my-posh completion bash)"' >> ~/.bashrc && \
        unset configFile && \
        unset command
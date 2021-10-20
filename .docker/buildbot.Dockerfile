FROM devkitpro/devkitarm:20210726
CMD [ "/usr/local/bin/violet-entrypoint" ]
ENV WORKON_HOME /venv

RUN apt-get update --fix-missing && \
    apt-get install -y \
        libgl1-mesa-dev \
        gcc-arm-none-eabi \
        bc \
        cmake \
        python3-pip && \
    rm -rf /var/lib/apt/lists/*

RUN pip3 install --upgrade pip
RUN pip3 install pipenv
RUN mkdir -p /etc/violet
WORKDIR /etc/violet

RUN \
        git clone https://github.com/ipatix/wav2agb.git && \
        directory=$(pwd) && \
        cd wav2agb && \
        git checkout 3acb19c8d11d017d39d77a87fa8630d07945a6c4 && \
        make && \
        chmod 744 wav2agb && \
        install -t /usr/local/bin ./wav2agb && \
        cd $directory && \
        unset directory

RUN \
        git clone https://github.com/pret/pokefirered.git && \
        directory=$(pwd) && \
        cd pokefirered/tools/mid2agb && \
        git checkout 7b8c935926eec33651e0e265fa49f2f99fce918a && \
        make && \
        chmod 744 mid2agb && \
        install -t /usr/local/bin ./mid2agb && \
        cd $directory && \
        unset directory
RUN \
        git clone https://github.com/Kingcom/armips.git && \
        directory=$(pwd) && \
        cd armips && \
        git checkout v0.11.0 && \
        cmake . && \
        make && \
        chmod 744 armips && \
        install -t /usr/local/bin ./armips && \
        cd $directory && \
        unset directory
RUN \
        git clone https://github.com/WodkaRHR/gba-mus-ripper.git && \
        directory=$(pwd) && \
        cd gba-mus-ripper && \
        git checkout a1c8ed924420fa7f2a311f61a88915aed8018bf9 && \
        make && \
        chmod 744 ./* && \
        install -t /usr/local/bin ./out/* && \
        cd $directory && \
        unset directory

WORKDIR /workspace
COPY .docker/buildbot-entrypoint.sh /usr/local/bin/violet-entrypoint
FROM gcc
ENTRYPOINT [ "/usr/local/bin/violet-entrypoint" ]

RUN apt-get update --fix-missing
RUN DEBIAN_FRONTEND=nointeractive apt-get install apt-utils -y
RUN apt-get install -y locales
RUN localedef -i en_US -c -f UTF-8 -A /usr/share/locale/locale.alias en_US.UTF-8

ENV LANG en_US.utf8
ENV DEBIAN_FRONTEND nointeractive
ENV PIPENV_VENV_IN_PROJECT true

RUN apt-get update --fix-missing
RUN apt-get install -y \
        libgl1-mesa-dev \
        gcc-arm-none-eabi \
        dos2unix \
        cmake \
        bc \
        python3-pip
RUN pip3 install pipenv

RUN \
        wget https://github.com/devkitPro/pacman/releases/download/devkitpro-pacman-1.0.1/devkitpro-pacman.deb -O pacman.deb; \
        dpkg -i pacman.deb; \
        dkp-pacman -S --noconfirm gba-dev; \
        rm pacman.deb;
ENV DEVKITPRO /opt/devkitpro
ENV DEVKITARM ${DEVKITPRO}/devkitARM
ENV DEVKITPPC ${DEVKITPRO}/devkitPPC
ENV PATH ${DEVKITPRO}/tools/bin:$PATH

RUN mkdir -p /etc/violet
WORKDIR /etc/violet
RUN \
        cd /etc/violet; \
        \
        git clone https://github.com/ipatix/wav2agb; \
        make -C wav2agb; \
        chmod 744 wav2agb/wav2agb; \
        cp wav2agb/wav2agb /usr/local/bin;
RUN \
        git clone https://github.com/pret/pokefirered.git; \
        make -C pokefirered/tools/mid2agb; \
        chmod 744 pokefirered/tools/mid2agb/mid2agb; \
        cp pokefirered/tools/mid2agb/mid2agb /usr/local/bin;
RUN \
        git clone https://github.com/Kingcom/armips.git; \
        directory=$(pwd); \
        cd armips; \
        cmake .; \
        cd $directory; \
        unset directory; \
        make -C armips; \
        chmod 744 armips/armips; \
        cp armips/armips /usr/local/bin;
RUN \
        git clone https://github.com/WodkaRHR/gba-mus-ripper.git /etc/violet/gba-mus-ripper; \
        make -C /etc/violet/gba-mus-ripper; \
        chmod 744 /etc/violet/gba-mus-ripper/out/*; \
        cp /etc/violet/gba-mus-ripper/out/* /usr/local/bin;

WORKDIR /usr/local/violet
COPY .docker/buildbot-entrypoint.sh /usr/local/bin/violet-entrypoint
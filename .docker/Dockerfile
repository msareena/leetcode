FROM ubuntu:22.10

ARG USER_NAME=docker-user
ARG USER_HOME=/home/${USER_NAME}
ARG USER_UID=1000
ARG USER_GID=1000
ARG USER_SHELL=/bin/bash
ARG WORKSPACE=${USER_HOME}/workspace

RUN \
    apt-get update && \
    DEBIAN_FRONTEND="noninteractive" apt-get install -y \
    build-essential \
    cmake \
    gdb \
    git \
    openssh-server \
    rsync \
    ssh \
    sudo \
    vim && \
    apt-get clean

RUN \
    groupadd -g ${USER_GID} ${USER_NAME} && \
    useradd -m --uid ${USER_UID} --gid ${USER_GID} -G sudo \
            -s ${USER_SHELL} ${USER_NAME} && \
    mkdir ${WORKSPACE} && \
    chown -R ${USER_NAME}:${USER_NAME} ${WORKSPACE} && \
    echo ${USER_NAME} ALL=\(ALL\) NOPASSWD:ALL \
         > /etc/sudoers.d/${USER_NAME} && \
    chmod 0440 /etc/sudoers.d/${USER_NAME}

RUN ( \
    echo 'PermitRootLogin yes'; \
    echo 'PasswordAuthentication yes'; \
    echo 'Subsystem sftp /usr/lib/openssh/sftp-server'; \
  ) > /etc/ssh/sshd_config \
  && mkdir /run/sshd \
  && ssh-keygen -A \
  && echo 'root:docker' | chpasswd \
  && echo 'docker-user:docker' | chpasswd

WORKDIR ${WORKSPACE}

USER ${USER_NAME}

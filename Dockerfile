FROM ubuntu:23.04
RUN apt update && \
    apt install -y bison cmake flex gcc make python3 python3-pillow python3-numpy && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*
WORKDIR /root
CMD ["/bin/bash"]
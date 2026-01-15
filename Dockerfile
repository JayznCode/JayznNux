# 1.   ()
FROM ubuntu:22.04

# 2.      
ENV DEBIAN_FRONTEND=noninteractive

# 3.    (   -y  )
RUN apt-get update && apt-get install -y \
    nano \
    vim \
    zsh \
    git \
    curl \
    wget \
    ca-certificates \
    && rm -rf /var/lib/apt/lists/*

# 4. Oh My Zsh  (unattended )
RUN sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)" "" --unattended

# 5.    'robbyrussell'  ( )
RUN sed -i 's/ZSH_THEME="agnoster"/ZSH_THEME="robbyrussell"/' ~/.zshrc

# 6.   zsh 
ENTRYPOINT ["/bin/zsh"]

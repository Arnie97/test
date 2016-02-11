FROM rastasheep/ubuntu-sshd:latest
MAINTAINER Arnie97 <arnie97@gmail.com>

# install prerequisites
RUN apt-get update -q
RUN apt-get install -y ruby
RUN gem install travis

# clean up
RUN rm -rf /var/lib/apt/lists/*

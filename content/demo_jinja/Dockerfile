FROM debian:11
RUN apt update && apt upgrade -y
RUN apt install -y python3-pip
RUN pip install --upgrade pip
RUN pip install Jinja2
WORKDIR /srv
CMD ["bash"]




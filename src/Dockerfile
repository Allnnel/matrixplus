FROM ubuntu:latest
RUN apt-get update \
    && apt-get  install valgrind --no-install-recommends -y\
    g++\
    make \
    libgtest-dev 
COPY . /app
WORKDIR /app
RUN make all
CMD valgrind --leak-check=full -s ./tests/Matrix_test

# Перед запуском dockerfile в кампусе, откройте приложение докер и выполните команды
# rm -rf ~/Library/Containers/com.docker.docker
# mkdir -p ~/goinfre/Docker/Data
# ln -s ~/goinfre/Docker ~/Library/Containers/com.docker.docker
# После, выполните команду в директории где находится dockerfile
# Не забудь отчистить проект (make clean) перед запуском 
# docker build -t myproject .
# docker run --name myprog myproject
# docker rm myprog
# docker rmi myproject
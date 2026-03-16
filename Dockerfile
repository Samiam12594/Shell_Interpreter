FROM ubuntu:22.04

RUN apt-get update && apt-get install -y g++ build-essential

WORKDIR /app

COPY . .

RUN g++ -std=c++20 -o shell main.cpp

CMD ["./shell"]
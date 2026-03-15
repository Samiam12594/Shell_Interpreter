# Shell Interpreter — A Journey in Reinventing the Wheel

## Overview
This project is an ongoing documentation of my journey building a shell interpreter similar to Bash from the ground up.

The goal is not to ship something production-ready. The goal is to deeply understand what actually goes into building something of this kind — process management, parsing, syscalls, and everything in between.

## Motivation
I have always had an interest in low level programming and hardware architecture. This is the first project where I seriously investigate that interest and put it on record.

With speed and efficiency dominating today's tech landscape, my concern is that AI is increasingly being used to offload critical thinking to an agent — quietly eroding the ability to truly problem solve and understand what you are building.

My goal is to keep incentivizing real skill development through the slow, unglamorous process of actual development.

## Ground Rules
- Written entirely by hand
- Little to no LLM assistance (except formatting this document)
- Documented as I go, including the wrong turns

## Built With
- C++
- Docker

## Running with Docker 
Ensure you are in the *Shell_interpreter* directory/project folder:
```bash
docker build -t myshell .
docker run -it myshell
```

## Follow Along
This is a living project. If you are on a similar journey, I hope you come along for it.
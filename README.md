# Coding Challenge - Embedded Intent Recognizer
Embedded Intent Recognizer command line tool


# Description
This is a command line tool developed using c++ and cmake that predicts the intention from the user provided input.

# How to build tooling
- Build application: mkdir build && cd build && cmake ..  && make 

- Run application: ./IntentRecognizer

- Build: mkdir build && cd build && cmake ..  && make

- Build clean: make clean && make


# How to run:
$ ./IntentRecognizer.exe What is the weather like in Paris today?

Intent: Get Weather City Time

$ ./IntentRecognizer.exe What is the weather like today?

Intent: Get Weather

$ ./IntentRecognizer.exe Tell me an interesting fact

Intent: Get Fact

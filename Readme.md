# Hysteresis

In a microcontroller-based system, analogue to digital converter (ADC) is sensing analogue voltage coming on one of the
analogue channels. This analogue voltage needs to be converted into a discrete level (0-4) depending upon the value of
input voltage in such a way that some hysteresis is added to reject sudden voltage variations due to noise. Following
graph shows the relationship between analogue voltage read (%age) from the channel to the discrete level that need to be
encoded by the software. Write code that will perform this job. Use this prototype so the code can be tested: unsigned
int hysteresis(unsigned int input_percent)

Hysteresis Regions:

- For Analogue Input between 10 - 15: Level between 0 - 1
- For Analogue Input between 35 - 40: Level between 1 - 2
- For Analogue Input between 60 - 65: Level between 2 - 3
- For Analogue Input between 85 - 90: Level between 3 - 4

## Compilation

Run make to create the binary.

```bash
$ mkdir build
$ cd build
$ cmake ..
$ make
$ cd src
$ ./hysteresis
$ cd ../tst
$ ./unitTestHysteresis # To test and see results
```

## Code structure

Embedded Intent Recognizer has the tree structure given below:

```bash
├─── src
│   ├─── CMakeList.txt
│   ├─── hysteresis.c
│   ├─── hysteresis.h
│   ├─── main.c
├─── tst
│   ├─── CMakeList.txt
│   ├─── main.cpp
│   └─── testIntentRecognizer.cpp
├─── .gitignore
├─── LICENSE
└─── Readme.md
```

## Used third-party tools

This project is built, tested, and documented using some third-party tools and services listed below. All third-party
libraries are placed under the lib directory. I would like to thank them.

### [Hysteresis](https://github.com/lille-boy/hysteresis): Hysteresis function by lille-boy

This coding example is used because it has the same functional usage. This implementation is optimized for this usage.

### [Google Test](https://github.com/google/googletest): Google Test framework

GoogleTest is Google’s C++ testing and mocking framework. The GoogleTest is used for unit tests in this project due to
the following reasons:

- Platform independence (Linux, Mac, Windows)
- Independent and repeatable tests
- Easy to adapt and use
- Portability: Can portable between different compilers
- Speed: The tests run fast.

With configurations on CMakeLists.txt, the Google Test content is fetched. To follow current Google Test commits, it is
useful to update URL in CMakeLists.txt frequently.

## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License

MIT License

Copyright (c) [2022] [Ege ENGIN]

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit
persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.ISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
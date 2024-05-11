
 
# MiniC Compiler: A Learning Experience in Compilation

This project delves into the world of compilers, specifically focusing on building a compiler for the miniC language. Developed for a Compilers course at the University of Murcia (2nd year Computer Engineering), this project uses C, Flex, and Bison to explore the fundamental concepts of compilation, lexical analysis, and syntactic analysis.

## Project Goals:

- Gain practical experience in compiler construction.
- Understand the process of lexical analysis using tools like Flex.
- Grasp the concepts of syntactic analysis with the help of Bison.
- Apply these techniques to build a compiler for a simplified C-like language (miniC).

## Technology Stack:

- **C:** The primary programming language for building the compiler itself.
- **Flex:** A lexical analyzer generator used to break down the miniC source code into tokens.
- **Bison:** A parser generator that helps define the grammar rules for the miniC language.

## Target Audience:

This project is geared towards computer engineering students, particularly those enrolled in a Compilers course (2nd year) at the University of Murcia. It provides a hands-on learning experience for anyone interested in understanding the inner workings of compilers.

## Getting Started:

To execute the necessary compilation directives to run the project, we will use the `make` tool. In the root directory of the project, execute the `make` command, which will automatically perform all necessary actions, ultimately creating the `miniCCompiler` file, corresponding to our executable.

After this, you can execute the `make run` command, which will compile the `testFile.mc` file located in the root directory, or alternatively use the `miniCCompiler` binary as follows:

```bash
./miniCCompiler inputfile.mc > compiledfile.s

## Disclaimer:

This project serves as an educational tool and might not be a fully-fledged, production-ready compiler.

## License:

(Specify the license under which the project is distributed)

# FlexBison XML Compiler

A compiler for XML documents implemented in C using **Flex** for 
lexical analysis and **Bison** for syntax parsing.

## Overview

This project implements a full compiler pipeline for XML input:

1. **Lexical Analysis** (`lexical.l`) — Flex tokenizes the XML input,
   recognizing tags, attributes, text content, and special characters.
2. **Syntax Parsing** (`grammar.y`) — Bison defines the grammar rules
   and validates the structure of the XML document.
3. **Hash Table** (`hashtbl.h`, `token.h`) — Supporting data structures
   used during the compilation process.

## Project Structure

| File | Description |
|------|-------------|
| `lexical.l` | Flex lexer — tokenizes XML input |
| `grammar.y` | Bison grammar — parses token stream |
| `lex.yy.c` | Auto-generated C code from Flex |
| `grammar.tab.c/h` | Auto-generated C code from Bison |
| `hashtbl.h` | Hash table implementation |
| `token.h` | Token definitions |
| `CodeXML.xml` | Sample XML input file |
| `run.sh` | Build & run script |

## How to Run

```bash
chmod +x run.sh
./run.sh
```

Or manually:

```bash
flex lexical.l
bison -d grammar.y
gcc lex.yy.c grammar.tab.c -o xml_compiler -lfl
./xml_compiler < CodeXML.xml
```

## Technologies

- C
- Flex (Fast Lexical Analyzer)
- Bison (GNU Parser Generator)

## Context

University project — Compilers course. Demonstrates core compiler
construction concepts: tokenization, BNF grammar design, and
syntax validation of XML documents.

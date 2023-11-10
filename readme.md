# README

## Very Simple Vector Database in C

This repository contains a simple implementation of a non-permanent vector database in C. The primary purpose of this code is to demonstrate basic vector operations and provide a foundation for understanding cosine distance calculations. The database allows for the insertion of vectors with associated metadata and provides a function to find the closest vector to a given query vector.

### Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Functions](#functions)
- [Sample Usage](#sample-usage)

---

### Overview

The code defines a structure called `Embedding` to represent vectors with associated metadata. The database (`db`) is an array of `Embedding` structures, and it can hold up to `MAX_EMBEDDINGS` entries. The vectors are three-dimensional, as specified by `VECTORS_DIMENSIONS`.

### Usage

To use this code, follow these steps:

1. Clone the repository.

   ```bash
   git clone https://github.com/tommaso-merlini/HedgeHog.git
   ```

2. Navigate to the directory containing the code.

   ```bash
   cd HedgeHog
   ```

3. Compile the code using your preferred C compiler.

   ```bash
   gcc vector_db.c -o vector_db
   ```

4. Run the compiled executable.
   ```bash
   ./vector_db
   ```

### Functions

1. **`main` function:**

   - Initializes the vector database (`db`).
   - Creates sample vectors (`vec1`, `vec2`, `vec3`) with associated metadata.
   - Inserts `vec1` and `vec2` into the database.
   - Searches for the closest vector to `vec3` and prints the associated metadata.

2. **`topEmbedding` function:**

   - Takes a query vector, the database, and the number of dimensions as input.
   - Returns the closest vector in the database to the query vector based on cosine distance.

3. **Cosine Distance-related functions:**
   - `cosineDistance`: Calculates the cosine distance between two vectors.
   - `cosineNumerator`: Calculates the numerator part of the cosine distance formula.
   - `cosineDenominator`: Calculates the denominator part of the cosine distance formula.

### Sample Usage

```c
// Create sample vectors
Embedding vec1 = {.vector = {0, 0, 0}, .metadata = "vec1"};
Embedding vec2 = {.vector = {0, 0, 2}, .metadata = "vec2"};
Embedding vec3 = {.vector = {0, 0, 100}, .metadata = "vec3"};

// Insert vectors into the database
db[0] = vec1;
db[1] = vec2;

// Search for the closest vector to vec3
Embedding result = topEmbedding(vec3.vector, db, VECTORS_DIMENSIONS);

// Print the metadata of the closest vector
printf("Closest Vector: %s\n", result.metadata);
```

Feel free to explore and modify the code for your specific use case or integrate it into a larger project.

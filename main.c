#include<stdio.h>
#include<math.h>

#define VECTORS_DIMENSIONS 3
#define MAX_EMBEDDINGS 100
#define MAX_METADATA_CHARS 100

typedef struct {
  float   vector[VECTORS_DIMENSIONS];
  char metadata[MAX_METADATA_CHARS];
} Embedding;

float cosineDistance(float vec1[], float vec2[], int dimensions);
float cosineNumerator(float vec1[], float vec2[], int dimensions);
float cosineDenominator(float vec1[], float vec2[], int dimensions);
Embedding topEmbedding(float vector[], Embedding db[], int dimensions);

void main(void) {
    //init db
    Embedding db[MAX_EMBEDDINGS] = {};
    
    //create some sample vectors
    Embedding vec1;
    Embedding vec2;
    Embedding vec3;

    vec1 = (Embedding){.vector = {-0.021426061, -0.00665704, 0.020520154}, .metadata = "vec1" };
    vec2 = (Embedding){.vector = {-0.0204378, -0.017829886, 0.008949257}, .metadata = "vec2"};
    vec3 = (Embedding){.vector = {-0.01877697, 0.010980684, -0.01781616}, .metadata = "vec3"};

    //insert only vec1 and vec2 in db
    db[0] = vec1;
    db[1] = vec2;

    //now search the closest vector to vec3 -> vec2
    Embedding result = topEmbedding(vec3.vector, db, VECTORS_DIMENSIONS);
    printf("%s", result.metadata);
}

Embedding topEmbedding(float vector[], Embedding db[], int dimensions) {
    Embedding topEmbedding;
    float topScore;

    int i = 0;
    while(i < MAX_EMBEDDINGS) {
        float distance = cosineDistance(vector, db[i].vector, dimensions);

        if(distance > topScore) {
            topEmbedding = db[i];
            topScore = distance;
        }

        i = i + 1;
    }

    return topEmbedding;
}

float cosineDistance(float vec1[], float vec2[], int dimensions) {
    float distance = cosineNumerator(vec1, vec2, dimensions) / cosineDenominator(vec1, vec2, dimensions);

    return distance;
}

float cosineNumerator(float vec1[], float vec2[], int dimensions) {
    float sum = 0; 
    for(int i = 0; i < dimensions; i++) {
        sum += vec1[i] * vec2[i];
    }

    return sum;
}

float cosineDenominator(float vec1[], float vec2[], int dimensions) {
    float firstRooting = 0;
    for(int i = 0; i < dimensions; i++) {
        firstRooting += vec1[i] * vec1[i];
    }

    float secondRooting = 0;
    for(int i = 0; i < dimensions; i++) {
        secondRooting += vec2[i] * vec2[i];
    }

    float denominator = sqrt(firstRooting) * sqrt(secondRooting);

    return denominator;
} 
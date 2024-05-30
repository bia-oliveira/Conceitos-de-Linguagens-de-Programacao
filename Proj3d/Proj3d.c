#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function prototypes
void generate_pcode(const char* intermediate_code, int* lod_counter);

int main() {
    // Example code
    const char* code[] = {
        "PUSH(a)",
        "PUSH(b)",
        "y=POP(); x=POP(); PUSH(x MUL y)",
        "PUSH(c)",
        "y=POP(); x=POP(); PUSH(x SUB y)",
        "\n",
        "PUSH(a)",
        "PUSH(b)",
        "y=POP(); x=POP(); PUSH(x ADD y)",
        "PUSH(c)",
        "y=POP(); x=POP(); PUSH(x MUL y)",
        "\n",
        "PUSH(d)",
        "PUSH(e)",
        "y=POP(); x=POP(); PUSH(x ADD y)",
        "\n",
        "PUSH(a)",
        "PUSH(b)",
        "y=POP(); x=POP(); PUSH(x SUB y)",
        "PUSH(c)",
        "y=POP(); x=POP(); PUSH(x DIV y)",
        "\n",
        "PUSH(d)",
        "PUSH(e)",
        "y=POP(); x=POP(); PUSH(x MUL y)",
        "PUSH(a)",
        "y=POP(); x=POP(); PUSH(x ADD y)",
        "\n",
        "PUSH(b)",
        "PUSH(c)",
        "PUSH(d)",
        "y=POP(); x=POP(); PUSH(x SUB y)",
        "y=POP(); x=POP(); PUSH(x ADD y)",
        "\n",
        "PUSH(c)",
        "PUSH(a)",
        "PUSH(b)",
        "y=POP(); x=POP(); PUSH(x ADD y)",
        "y=POP(); x=POP(); PUSH(x MUL y)",
        "\n",
        "PUSH(e)",
        "PUSH(d)",
        "y=POP(); x=POP(); PUSH(x DIV y)",
        "\n",
        "PUSH(a)",
        "PUSH(b)",
        "y=POP(); x=POP(); PUSH(x MUL y)",
        "\n",
        "PUSH(a)",
        "PUSH(b)",
        "y=POP(); x=POP(); PUSH(x DIV y)",
        "PUSH(c)",
        "y=POP(); x=POP(); PUSH(x SUB y)"
    };

    // Number of lines in the code
    size_t num_lines = sizeof(code) / sizeof(code[0]);

    // Counter to track the LOD instruction
    int lod_counter = 3;

    // Generate P-code for each line of the code
    for (size_t i = 0; i < num_lines; i++) {
      if (strcmp(code[i], "\n") == 0) {
        printf("\n");
      } else {
        generate_pcode(code[i], &lod_counter);
      }
    }

    return 0;
}

void generate_pcode(const char* intermediate_code, int* lod_counter) {
    if (strncmp(intermediate_code, "PUSH(", 5) == 0) {
        // Extract the variable after PUSH(
        char var;
        sscanf(intermediate_code, "PUSH(%c)", &var);
      
        if (var == 'a'){
          printf("LOD 0 3\n");
        } else if (var == 'b'){
          printf("LOD 0 4\n");
        } else if (var == 'c'){
          printf("LOD 0 5\n");
        } else if (var == 'd'){
          printf("LOD 0 6\n");
        } else if (var == 'e'){
          printf("LOD 0 7\n");
        }
      
    } else if (strstr(intermediate_code, "y=POP(); x=POP(); PUSH(x ADD y)") != NULL) {
        printf("OPR 0 2\n");
    } else if (strstr(intermediate_code, "y=POP(); x=POP(); PUSH(x SUB y)") != NULL) {
        printf("OPR 0 3\n");
    } else if (strstr(intermediate_code, "y=POP(); x=POP(); PUSH(x MUL y)") != NULL) {
        printf("OPR 0 4\n");
    } else if (strstr(intermediate_code, "y=POP(); x=POP(); PUSH(x DIV y)") != NULL) {
        printf("OPR 0 5\n");
    } else {
        fprintf(stderr, "Unknown operation: %s\n", intermediate_code);
        exit(1);
    }
}

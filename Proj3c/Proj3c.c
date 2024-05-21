#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function prototypes
void generate_pcode(const char* intermediate_code);

// Example expressions as arrays of strings
const char* expressions[][10] = {
    {"PUSH(1)", "PUSH(2)", "y=POP(); x=POP(); PUSH(x ADD y)"},
    {"PUSH(3)", "PUSH(4)", "y=POP(); x=POP(); PUSH(x MUL y)"},
    {"PUSH(5)", "PUSH(6)", "y=POP(); x=POP(); PUSH(x DIV y)"},
    {"PUSH(7)", "PUSH(8)", "y=POP(); x=POP(); PUSH(x SUB y)"},
    {"PUSH(9)", "PUSH(10)", "PUSH(11)", "y=POP(); x=POP(); PUSH(x MUL y)", "y=POP(); x=POP(); PUSH(x ADD y)"},
    {"PUSH(12)", "PUSH(13)", "y=POP(); x=POP(); PUSH(x DIV y)", "PUSH(14)", "y=POP(); x=POP(); PUSH(x SUB y)"},
    {"PUSH(15)", "PUSH(16)", "y=POP(); x=POP(); PUSH(x ADD y)", "PUSH(17)", "y=POP(); x=POP(); PUSH(x MUL y)"},
    {"PUSH(18)", "PUSH(19)", "y=POP(); x=POP(); PUSH(x DIV y)", "PUSH(20)", "y=POP(); x=POP(); PUSH(x SUB y)"},
    {"PUSH(21)", "PUSH(22)", "PUSH(23)", "y=POP(); x=POP(); PUSH(x MUL y)", "y=POP(); x=POP(); PUSH(x ADD y)"},
    {"PUSH(24)", "PUSH(25)", "y=POP(); x=POP(); PUSH(x SUB y)", "PUSH(26)", "y=POP(); x=POP(); PUSH(x DIV y)"}
};

int main() {
    // Number of expressions
    size_t num_expressions = sizeof(expressions) / sizeof(expressions[0]);

    // Generate P-code for each expression
    for (size_t i = 0; i < num_expressions; i++) {
        printf("Expression %zu:\n", i + 1);
        size_t j = 0;
        while (expressions[i][j] != NULL) {
            generate_pcode(expressions[i][j]);
            j++;
        }
        printf("\n");
    }

    return 0;
}

void generate_pcode(const char* intermediate_code) {
    if (strncmp(intermediate_code, "PUSH(", 5) == 0) {
        // Extract the number after PUSH(
        int value;
        sscanf(intermediate_code, "PUSH(%d)", &value);
        printf("LIT 0 %d\n", value);
    } else if (strstr(intermediate_code, "PUSH(x ADD y)") != NULL) {
        printf("LOD 0 3\n");
        printf("LOD 0 4\n");
        printf("OPR 0 2\n");
    } else if (strstr(intermediate_code, "PUSH(x SUB y)") != NULL) {
        printf("LOD 0 3\n");
        printf("LOD 0 4\n");
        printf("OPR 0 3\n");
    } else if (strstr(intermediate_code, "PUSH(x MUL y)") != NULL) {
        printf("LOD 0 3\n");
        printf("LOD 0 4\n");
        printf("OPR 0 4\n");
    } else if (strstr(intermediate_code, "PUSH(x DIV y)") != NULL) {
        printf("LOD 0 3\n");
        printf("LOD 0 4\n");
        printf("OPR 0 5\n");
    } else {
        fprintf(stderr, "Unknown operation: %s\n", intermediate_code);
        exit(1);
    }
}

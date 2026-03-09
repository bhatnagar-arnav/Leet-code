int evalRPN(char **tokens, int tokensSize) {
    int stack[tokensSize];
    int top = -1;

    for (int i = 0; i < tokensSize; i++) {
        char *t = tokens[i];

        if (!strcmp(t, "+")) {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = a + b;
        } else if (!strcmp(t, "-")) {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = a - b;
        } else if (!strcmp(t, "*")) {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = a * b;
        } else if (!strcmp(t, "/")) {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = a / b;  
        } else {
            stack[++top] = atoi(t);  
        }
    }

    return stack[top];
}

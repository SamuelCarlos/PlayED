#include <stdio.h>
#include <stdlib.h>

#include "application.h"

int main(void) {    
    int application = startApplication();
    printf("%d", application);
    return 0;
}
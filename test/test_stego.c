#include "../include/stego.h"
#include "../include/utils.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

int main() {
    char secret_message[] = "This is a secret message.";
    char extracted_message[100];

    StegoParams params = {
        .cover_image_path = "data/input.bmp",
        .stego_image_path = "data/stego.bmp",
        .secret_message = secret_message,
        .message_length = strlen(secret_message),
        .key = 12345
    };

    int result = embedMessage(&params);
    assert(result == 0);
    printf("Message embedded successfully.\n");

    result = extractMessage(params.stego_image_path, extracted_message, params.message_length);
    assert(result > 0);
    extracted_message[result] = '\0';
    printf("Message extracted: %s\n", extracted_message);

    assert(strcmp(secret_message, extracted_message) == 0);
    printf("Stego test passed!\n");

    return 0;
}

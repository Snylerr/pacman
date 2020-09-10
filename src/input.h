#ifndef __INPUT__
#define __INPUT__

typedef struct input_s
{
    bool up;
    bool down;
    bool left;
    bool right;

    bool enter;
    bool escape;

    bool exit;
} input_t;

void process_inputs(input_t input);

#endif

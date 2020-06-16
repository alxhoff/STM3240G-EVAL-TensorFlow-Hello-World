/* Copyright 2019 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/
#include <stdlib.h>

#include "tensorflow/lite/c/common.h"
#include "tensorflow/lite/kernels/internal/tensor_ctypes.h"

#include "main_functions.h"
#include "data_types.h"
#include "constants.h"

extern void sine_init();
extern void sine_invoke();

extern TfLiteTensor *sine_input(int idx=0);
extern TfLiteTensor *sine_output(int idx=0);

int inference_count = 0;

// The name of this function is important for Arduino compatibility.
void setup()
{
    sine_init();
}

// The name of this function is important for Arduino compatibility.
circle_t *loop()
{
	circle_t *ret = (circle_t *)malloc(sizeof(circle_t));
	if (!ret)
		return NULL;
	ret->size = 4;
	// Calculate an x value to feed into the model. We compare the current
	// inference_count to the number of inferences per cycle to determine
	// our position within the range of possible x values the model was
	// trained on, and use this to calculate a value.
	float position = static_cast<float>(inference_count) /
			 static_cast<float>(kInferencesPerCycle);
	float x_val = position * kXrange;

	// Place our calculated x value in the model's input tensor
    tflite::GetTensorData<float>(sine_input())[0] = x_val;


	// Run inference, and report any error
    sine_invoke();

	// Read the predicted y value from the model's output tensor
	float y_val = tflite::GetTensorData<float>(sine_output())[0];

	ret->x = x_val;
	ret->y = y_val;

	// Increment the inference_counter, and reset it if we have reached
	// the total number per cycle
	inference_count++;
	if (inference_count >= kInferencesPerCycle)
		inference_count = 0;

	return ret;
}

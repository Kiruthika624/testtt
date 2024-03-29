/*******************************************************************************
 * Copyright 2016-2019 ARM Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *******************************************************************************/

#include "test_runners.h"

int main(int argc, char * argv[])
{
    (void)argc;
    (void)argv;

    // the tests may actually assert on failure, so they may not return anything useful status
    // and a nonzero return value is typically a sign of platform initialization failure
    return palEntropyTestMain();
}


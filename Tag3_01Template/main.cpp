#include <iostream>
#include <memory>
#include "processor/CharacterCounter.h"
#include "processor/LineCounter.h"

using Processor = std::shared_ptr<processor::AbstractFileProcessor>;

int main() {
    Processor fileProcessor = std::make_shared<processor::LineCounter>();
    fileProcessor->run("..\\data\\blind.txt");
    return 0;
}

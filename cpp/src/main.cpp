#include "prediction.hpp"
#include "test.hpp"

#define OK 0
#define NOT_FOUND 1
#define ERROR 2

void respond_and_exit(unique_ptr<Prediction> prediction) {
    if (prediction == nullptr) {
        exit(NOT_FOUND);
    } else {
        print(std::move(prediction));
        exit(OK);
    }
}


vector<int>* parse_or_exit(int argc, char *argv[]) {

    if (argc == 1) {
        exit(NOT_FOUND);
    }

    if (!strcmp(argv[1], "--tests")) {
        run_tests();
        exit(OK);
    }

    if (argc == 2) {
        exit(NOT_FOUND);
    }

    auto numbers = new vector<int>;
    for (int i = 1; i < argc; i++) {
        try {
            int number = std::stoi(argv[i]);
            numbers->push_back(number);
        }
        catch (...) {
            exit(ERROR);
        }
    }
    return numbers;
}


int main(int argc, char *argv[]) {
    vector<int>* numbers = parse_or_exit(argc, argv);
    respond_and_exit(predict(*numbers));
    return OK;
}

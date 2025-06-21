class SimpleClass {
};

int main() {
    SimpleClass* sc1 = new SimpleClass;
    SimpleClass* sc2 = new SimpleClass[10];

    delete sc1;
    delete[] sc2;

    return 0;
}

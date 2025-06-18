
bool bar();

void foo(int x)
{
    if (x > 0) [[likely]] {
        // büyük ihtimalle çalışacak kod
    }

    bool error = bar();

    if (error) [[unlikely]] {
        
    }

}

enum Status {
    OK, 
    ERROR
};

void handle_ok();
void handle_error();

void baz(Status status)
{
    switch (status) {
    case OK: [[likely]]
        handle_ok();
        break;
    case ERROR: [[unlikely]]
        handle_error();
        break;
    }
}



struct IEventHandler {
    virtual void on_event(int code) = 0;
};

struct MyHandler : IEventHandler {
    void on_event([[maybe_unused]] int code) override {
        // base class interface gereği
    }
};

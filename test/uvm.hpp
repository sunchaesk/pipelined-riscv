
#ifndef UVM_H
#define UVM_H

// riscv input interface transaction item class
class RiscvInTx {
    private:
    public:
        RiscvInTx();
        ~RiscvInTx();
};

class RiscvOutTx {
    private:
    public:
        RiscvOutTx();
        ~RiscvOutTx();
};

class RiscvScoreBoard {
    private:
    public:
        RiscvScoreBoard();
        ~RiscvScoreBoard();
};

class RiscvInDriver {
    private:
    public:
        RiscvInDriver();
        ~RiscvInDriver();
};

class RiscvInMonitor {
    private:
    public:
        RiscvInMonitor();
        ~RiscvInMonitor();
};

class RiscvOutMonitor {
    private:
    public:
        RiscvOutMonitor();
        ~RiscvOutMonitor();
};

#endif

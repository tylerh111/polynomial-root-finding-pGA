//
// Created by tdh5188 on 4/12/18.
//

#ifndef POLYNOMIAL_ROOT_FINDING_PGA_PROCESS_H
#define POLYNOMIAL_ROOT_FINDING_PGA_PROCESS_H

#include <mpi.h>

//Abstract Class
class Process {
protected:
    int pid{-1};
    std::string pname;

public:
    static int networkSize;
    const static int MASTER_PID = 0;

    Process() : pname("") { };
    Process(int pid, std::string pname);

    virtual ~Process() = default;

    inline const int getPId()           const { return pid; }
    inline const std::string getPName() const { return pname; }
    inline const int getNetworkSize()   const { return Process::networkSize; }

    static void setNetworkSize(int networkSize);

    virtual int mainProcedure() = 0;


    class NetworkSizeException : public std::runtime_error{
    public:
        explicit NetworkSizeException(const std::string &msg = "Network size is too small")
                : runtime_error(msg) {}
    };

};


#endif //POLYNOMIAL_ROOT_FINDING_PGA_PROCESS_H

# define app

// Appends something to a file...



class SDKCompileFile {
private:
    std::string name;
public:
    void setName(const char* newname) {
        name = newname;
    }
    void append(const char* text) {
        std::ofstream ifile(name, std::ios::app);
        ifile << text;
    }
};

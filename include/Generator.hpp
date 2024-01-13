
#ifndef Generator_hpp
#define Generator_hpp

class Generator
{
public:
    Generator(double quantity);
    Generator(const Generator&);
    int generate();
    void startGenerating();
    void stopGenerating();
    void changequantity(double num);
    Generator operator=(const Generator&);
private:
    bool generating = false;
    double quantity = 1;
};

#endif /* Generator_hpp */

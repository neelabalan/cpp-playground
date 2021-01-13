#include <random>

template <typename RealType>
class GenerateRandomNumber
{
    private :
        RealType randomNumber;

    static_assert( std::is_same<RealType,              short>::value
                || std::is_same<RealType,                int>::value
                || std::is_same<RealType,               long>::value
                || std::is_same<RealType,          long long>::value
                || std::is_same<RealType,     unsigned short>::value
                || std::is_same<RealType,       unsigned int>::value
                || std::is_same<RealType,      unsigned long>::value
                || std::is_same<RealType, unsigned long long>::value
                || std::is_same<RealType,              float>::value
                || std::is_same<RealType,             double>::value
                || std::is_same<RealType,        long double>::value,
                "only real number values can be used");

        // create object for seeding
        std::random_device random_device; 

        // create engine and seed it
	// to seed mersenne twister
        std::mt19937 engine {random_device()}; 

    public:
        GenerateRandomNumber() = default;
        ~GenerateRandomNumber() = default;

        RealType setRangeForGeneration(RealType min, RealType max)
        {
            // create distribution for integers with [min; max] range
            std::uniform_real_distribution<> dist(min, max); 

            // finally get a pseudo-randomrandom integer number
            randomNumber = dist(engine); 
            return randomNumber;
        }

        RealType randBoolean()
        {
            std::uniform_int_distribution<> dist(0, 1);
            bool randomBool = dist(engine);
            return randomBool;
        }

        int getRandomNumber() { return randomNumber; }
        
};

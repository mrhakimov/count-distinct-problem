#include <set>
#include <random>
#include <cassert>
#include <bitset>
#include <math.h>

class UniqCounter {
public:
    void add(int x) {
        data.set(FNV_1a(x));
    }

    int get_uniq_num() const {
        double error = 1.0 - static_cast<double>(data.count()) / memory;
        int answer = memory;
        if (error - 0 > EPS) {
            answer *= -log(error);
        }
        return answer;
    }

private:
    static constexpr size_t memory = 262144; // 32 * 1024 * 8
    std::bitset<memory> data;
    constexpr static const double EPS = 0.0000000001; // 10 ^ (-10)
    const unsigned int FNV_offset_basis = 2166136261;
    const unsigned int FNV_prime = 16777619;

    unsigned int FNV_1a(unsigned int currentData) {
        unsigned int hash = FNV_offset_basis;
        const auto *byte_of_data = (const unsigned char *) &currentData;
        for (size_t i = 0; i < 4; i++) {
            hash = hash ^ (*byte_of_data++);
            hash = hash * FNV_prime;
        }
        return hash % memory;
    }
};

double relative_error(int expected, int got) {
    return abs(got - expected) / (double) expected;
}

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());

    const int N = (int) 1e6;
    for (int k : {1, 10, 1000, 10000, N / 10, N, N * 10}) {
        std::uniform_int_distribution<> dis(1, k);
        std::set<int> all;
        UniqCounter counter;
        for (int i = 0; i < N; i++) {
            int value = dis(gen);
            all.insert(value);
            counter.add(value);
        }
        int expected = (int) all.size();
        int counter_result = counter.get_uniq_num();
        double error = relative_error(expected, counter_result);
        printf("%d numbers in range [1 .. %d], %d uniq, %d result, %.5f relative error\n", N, k, expected,
               counter_result, error);
        assert(error <= 0.1);
    }

    return 0;
}

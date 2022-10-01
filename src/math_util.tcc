namespace util {
    template<typename T> T clamp(T min, T max, T value)
    {
        if (value < min)
            return min;

        if (value > max)
            return max;

        return value;
    }
}

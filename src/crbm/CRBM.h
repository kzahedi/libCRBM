#ifndef __CRBM_H__
#define __CRBM_H__

#include <matrix/Matrix.h>

namespace libcrbm
{
  namespace binary
  {
    class CRBM 
    {
      public:

        CRBM(int k, int n, int m, int uditerations, int bins);
        ~CRBM();

        void learn(Matrix& x, Matrix& y);
        void control(Matrix& x, Matrix& y);

        void up(Matrix& y, Matrix& x);
        void down(Matrix& z, Matrix& x);

        void initRandomWeights(double w = 0.01);
        void initInputBiasValues(double b = 0.01);
        void initHiddenBiasValues(double c = 0.01);

        int n() {return _n;};
        int m() {return _m;};
        int k() {return _k;};
        int uditerations() {return _uditerations;};

        double W(int i, int j) {return _W(i,j);};
        double V(int i, int j) {return _V(i,j);};
        double b(int i)        {return _b(i,0);};
        double c(int i)        {return _c(i,0);};

        const Matrix& W() {return _W;};
        const Matrix& V() {return _V;};
        const Matrix& b() {return _b;};
        const Matrix& c() {return _c;};

        void changeb(Matrix& db);
        void changec(Matrix& dc);
        void changeb(double alpha);
        void changec(double alpha);

        void setW(Matrix& W);
        void setV(Matrix& V);
        void setb(Matrix& b);
        void setc(Matrix& c);

        const Matrix& z() { return _z; }
        void  initLearning(int n);

        int bins() {return _bins;};


      private:

        double __sigm(double v);

        int    _n;            // number of output units
        int    _m;            // number of hidden units
        int    _k;            // number of input units
        int    _uditerations; // number of up-down iterations
        int    _bins;

        Matrix _W;            // interaction weights between hidden and outputs
        Matrix _Wt;           // transposed W
        Matrix _V;            // interaction weights between hidden and inputs
        Matrix _b;            // bias values for output
        Matrix _c;            // bias values for hidden

        Matrix _z;
    };
  }
}

#endif // __CRBM_H__


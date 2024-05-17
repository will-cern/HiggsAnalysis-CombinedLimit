#ifndef VectorizedExponential_h
#define VectorizedExponential_h

#include <RooExponential.h>
#include <RooAbsData.h>
#include "HGGRooPdfs.h"
#include <vector>

class VectorizedExponential {
    public:
        VectorizedExponential(const RooExponential &pdf, const RooAbsData &data, bool includeZeroWeights=false) ;
        void fill(std::vector<Double_t> &out) const ;
    private:
        const RooRealVar * x_;
        const RooAbsReal * lambda_;
        std::vector<Double_t> xvals_;
        mutable std::vector<Double_t> work_;
};
// An implementation of RooPower was added to ROOT from 6.28 onwards
#include "RVersion.h"

#if ROOT_VERSION_CODE < ROOT_VERSION(6, 28, 00)
class VectorizedPower {
    public:
        VectorizedPower(const RooPower &pdf, const RooAbsData &data, bool includeZeroWeights=false) ;
        void fill(std::vector<Double_t> &out) const ;
    private:
        const RooRealVar * x_;
        const RooAbsReal * exponent_;
        std::vector<Double_t> xvals_;
        mutable std::vector<Double_t> work_;
};
#endif

#endif

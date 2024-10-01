#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <memory>
using namespace std;

class Bank{
    public:
        virtual string getBankName() = 0;
        virtual string getEstablishedDate() = 0;;
        virtual string getBankType() = 0;
        virtual string getBranchName() = 0;
        virtual void getBankInfo() = 0;
        virtual ~Bank(){}
};
class Loan{
    public:
        virtual void getAvailableLoans() = 0;
        virtual double getInterestRate(string loanType) = 0;
        virtual void getRequiredDocuments(string loanType) = 0;
        virtual ~Loan(){};
};

class HDFC : public Bank, public Loan{
    private:
        string bankName;
        string estaDate;
        string bankType;
        string branchName;
        vector<string> availableLoans;
        map<string, double> interestRate;
        map<string, vector<string> > requiredDocuments;
    public:
        HDFC(){
            bankName = "HDFC Bank";
            estaDate = "10th August 2002";
            bankType = "Private";
            branchName = "Chennai";

            availableLoans = vector<string>();
            availableLoans.push_back("GoldLoan");
            availableLoans.push_back("LandLoan");
            availableLoans.push_back("PersonalLoan");

            interestRate["GoldLoan"] = 7.5;
            interestRate["LandLoan"] = 8.0;
            interestRate["PersonalLoan"] = 10.5;

             requiredDocuments["GoldLoan"] = vector<string>();
            requiredDocuments["GoldLoan"].push_back("ID Proof");
            requiredDocuments["GoldLoan"].push_back("Aadhar Card");
            requiredDocuments["GoldLoan"].push_back("Gold Bill");

            requiredDocuments["LandLoan"] = vector<string>();
            requiredDocuments["LandLoan"].push_back("ID Proof");
            requiredDocuments["LandLoan"].push_back("Aadhar Card");
            requiredDocuments["LandLoan"].push_back("Land Documents");

            requiredDocuments["PersonalLoan"] = vector<string>();
            requiredDocuments["PersonalLoan"].push_back("ID Proof");
            requiredDocuments["PersonalLoan"].push_back("Aadhar Card");
            requiredDocuments["PersonalLoan"].push_back("Personal Details");
        }
        string getBankName() override {
            return bankName;
        }
        string getEstablishedDate() override {
            return estaDate;
        }
        string getBankType() override {
            return bankType;
        }
        string getBranchName() override {
            return branchName;
        }
        void getBankInfo() override {
            cout << "Bank Name: " << bankName << endl 
                 << "Established Date: " << estaDate << endl
                 << "Bank Type: " << bankType << endl
                 << "Branch Name: " << branchName << endl;
        }
        void getAvailableLoans() override {
            for(int i=0; i<availableLoans.size();i++){
                cout << availableLoans[i] << " ";
            }
            cout << endl;
        }
        double getInterestRate(string loanType) override {
            return interestRate[loanType];
        }
        void getRequiredDocuments(string loanType) override {
            for(int i=0; i<requiredDocuments[loanType].size();i++){
                cout << requiredDocuments[loanType][i] << " ";
            }
            cout << endl;
        }
        ~HDFC() override {}
};

class SBI : public Bank, public Loan{

    private:
        string bankName;
        string estaDate;
        string bankType;
        string branchName;
        vector<string> availableLoans;
        map<string, double> interestRate;
        map<string, vector<string> > requiredDocuments;
    public:
        SBI(){
            bankName = "SBI Bank";
            estaDate = "10th Sept 2003";
            bankType = "Public";
            branchName = "Chennai";

            availableLoans = vector<string>();
            availableLoans.push_back("GoldLoan");
            availableLoans.push_back("LandLoan");
            availableLoans.push_back("PersonalLoan");

            interestRate["GoldLoan"] = 8.1;
            interestRate["LandLoan"] = 9.0;
            interestRate["PersonalLoan"] = 11.5;

            requiredDocuments["GoldLoan"] = vector<string>();
            requiredDocuments["GoldLoan"].push_back("ID Proof");
            requiredDocuments["GoldLoan"].push_back("Aadhar Card");
            requiredDocuments["GoldLoan"].push_back("Gold Bill");
            requiredDocuments["GoldLoan"].push_back("Receipt");

            requiredDocuments["LandLoan"] = vector<string>();
            requiredDocuments["LandLoan"].push_back("ID Proof");
            requiredDocuments["LandLoan"].push_back("Aadhar Card");
            requiredDocuments["LandLoan"].push_back("Land Documents");
            requiredDocuments["LandLoan"].push_back("Property Tax");

            requiredDocuments["PersonalLoan"] = vector<string>();
            requiredDocuments["PersonalLoan"].push_back("ID Proof");
            requiredDocuments["PersonalLoan"].push_back("Aadhar Card");
            requiredDocuments["PersonalLoan"].push_back("Personal Details");
        }
        string getBankName() override {
            return bankName;
        }
        string getEstablishedDate() override {
            return estaDate;
        }
        string getBankType() override {
            return bankType;
        }
        string getBranchName() override {
            return branchName;
        }
        void getBankInfo() override {
            cout << "Bank Name: " << bankName << endl 
                 << "Established Date: " << estaDate << endl
                 << "Bank Type: " << bankType << endl
                 << "Branch Name: " << branchName << endl;
        }
        void getAvailableLoans() override {
            for(int i=0; i<availableLoans.size();i++){
                cout << availableLoans[i] << " ";
            }
            cout << endl;
        }
        double getInterestRate(string loanType) override {
            return interestRate[loanType];
        }
        void getRequiredDocuments(string loanType) override {
            for(int i=0; i<requiredDocuments[loanType].size();i++){
                cout << requiredDocuments[loanType][i] << " ";
            }
            cout << endl;
        }
        ~SBI() override {}
};

class ICICI : public Bank, public Loan{
    private:
        string bankName;
        string estaDate;
        string bankType;
        string branchName;
        vector<string> availableLoans;
        map<string, double> interestRate;
        map<string, vector<string> > requiredDocuments;
    public:
        ICICI(){
            bankName = "ICICI Bank";
            estaDate = "27th Sept 2002";
            bankType = "Private";
            branchName = "Chennai";

            availableLoans = vector<string>();
            availableLoans.push_back("GoldLoan");
            availableLoans.push_back("LandLoan");
            availableLoans.push_back("PersonalLoan");

            interestRate["GoldLoan"] = 7.9;
            interestRate["LandLoan"] = 8.4;
            interestRate["PersonalLoan"] = 10.9;

            requiredDocuments["GoldLoan"] = vector<string>();
            requiredDocuments["GoldLoan"].push_back("ID Proof");
            requiredDocuments["GoldLoan"].push_back("Aadhar Card");
            requiredDocuments["GoldLoan"].push_back("Gold Bill");
            requiredDocuments["GoldLoan"].push_back("Sedharam");

            requiredDocuments["LandLoan"] = vector<string>();
            requiredDocuments["LandLoan"].push_back("ID Proof");
            requiredDocuments["LandLoan"].push_back("Aadhar Card");
            requiredDocuments["LandLoan"].push_back("Land Documents");
            requiredDocuments["LandLoan"].push_back("Owner Signature");

            requiredDocuments["PersonalLoan"] = vector<string>();
            requiredDocuments["PersonalLoan"].push_back("ID Proof");
            requiredDocuments["PersonalLoan"].push_back("Aadhar Card");
            requiredDocuments["PersonalLoan"].push_back("Personal Details");
            requiredDocuments["PersonalLoan"].push_back("Filled Challan");
        }
        string getBankName() override {
            return bankName;
        }
        string getEstablishedDate() override {
            return estaDate;
        }
        string getBankType() override {
            return bankType;
        }
        string getBranchName() override {
            return branchName;
        }
        void getBankInfo() override {
            cout << "Bank Name: " << bankName << endl 
                 << "Established Date: " << estaDate << endl
                 << "Bank Type: " << bankType << endl
                 << "Branch Name: " << branchName << endl; 
        }
        void getAvailableLoans() override {
            for(int i=0; i<availableLoans.size();i++){
                cout << availableLoans[i] << " ";
            }
            cout << endl;
        }
        double getInterestRate(string loanType) override {
            return interestRate[loanType];
        }
        void getRequiredDocuments(string loanType) override {
            for(int i=0; i<requiredDocuments[loanType].size();i++){
                cout << requiredDocuments[loanType][i] << " ";
            }
            cout << endl;
        }
        ~ICICI() override {}
};

class IndianBank : public Bank, public Loan{
    private:
        string bankName;
        string estaDate;
        string bankType;
        string branchName;
        vector<string> availableLoans;
        map<string, double> interestRate;
        map<string, vector<string> > requiredDocuments;
    public:
        IndianBank(){
            bankName = "Indian Bank";
            estaDate = "30th July 2003";
            bankType = "Public";
            branchName = "Chennai";

            interestRate["GoldLoan"] = 6.5;
            interestRate["LandLoan"] = 7.0;
            interestRate["PersonalLoan"] = 9.5;

            availableLoans = vector<string>();
            availableLoans.push_back("GoldLoan");
            availableLoans.push_back("LandLoan");
            availableLoans.push_back("PersonalLoan");


            requiredDocuments["GoldLoan"] = vector<string>();
            requiredDocuments["GoldLoan"].push_back("ID Proof");
            requiredDocuments["GoldLoan"].push_back("Aadhar Card");
            requiredDocuments["GoldLoan"].push_back("Gold Bill");
            requiredDocuments["GoldLoan"].push_back("Sedharam");
            requiredDocuments["GoldLoan"].push_back("Seikooli");

            requiredDocuments["LandLoan"] = vector<string>();
            requiredDocuments["LandLoan"].push_back("ID Proof");
            requiredDocuments["LandLoan"].push_back("Aadhar Card");
            requiredDocuments["LandLoan"].push_back("Land Documents");
            requiredDocuments["LandLoan"].push_back("Ownership");

            requiredDocuments["PersonalLoan"] = vector<string>();
            requiredDocuments["PersonalLoan"].push_back("ID Proof");
            requiredDocuments["PersonalLoan"].push_back("Aadhar Card");
            requiredDocuments["PersonalLoan"].push_back("Personal Details");
            requiredDocuments["PersonalLoan"].push_back("Property Details");
        }
        string getBankName() override {
            return bankName;
        }
        string getEstablishedDate() override {
            return estaDate;
        }
        string getBankType() override {
            return bankType;
        }
        string getBranchName() override {
            return branchName;
        }
        void getBankInfo() override {
            cout << "Bank Name: " << bankName << endl 
                 << "Established Date: " << estaDate << endl
                 << "Bank Type: " << bankType << endl
                 << "Branch Name: " << branchName << endl; 
        }
        void getAvailableLoans() override {
            for(int i=0; i<availableLoans.size();i++){
                cout << availableLoans[i] << " ";
            }
            cout << endl;
        }
        double getInterestRate(string loanType) override {
            return interestRate[loanType];
        }
        void getRequiredDocuments(string loanType) override {
            for(int i=0; i<requiredDocuments[loanType].size();i++){
                cout << requiredDocuments[loanType][i] << " ";
            }
            cout << endl;
        }

        ~IndianBank() override {}
};

//utility structure
struct BankLoanPair{
    Bank* bank;
    Loan* loan;
};

class Broker{
    //2 banks
    public:
    void compareInterestRates(BankLoanPair b1, BankLoanPair b2, string loanType){
        double rate1 = b1.loan->getInterestRate(loanType);
        double rate2 = b2.loan->getInterestRate(loanType);
        cout << "Comparing Interest rates of " << b1.bank->getBankName() << " & " << b2.bank->getBankName() << endl;

        if(rate1 < rate2){
            cout << "Interest Rate of " << b1.bank->getBankName() << "for " << loanType << " is lesser than that of " << b2.bank->getBankName() << endl;
        }
        else if(rate1 > rate2){
            cout << "Interest Rate of " << b2.bank->getBankName() << "for " << loanType << " is lesser than that of " << b1.bank->getBankName() << endl;
        }
        else{
            cout << "Interest Rate of " << b1.bank->getBankName() << "for " << loanType << " is same as that of " << b2.bank->getBankName() << endl;
        }
    }

    //3 banks
    void compareInterestRates(BankLoanPair b1, BankLoanPair b2, BankLoanPair b3, string loanType){
        double rate1 = b1.loan->getInterestRate(loanType);
        double rate2 = b2.loan->getInterestRate(loanType);
        double rate3 = b3.loan->getInterestRate(loanType);
        cout << "Comparing Interest rates of " << b1.bank->getBankName() << b2.bank->getBankName() << " & " << b3.bank->getBankName() << endl;

        if(rate1 < rate2 && rate1 < rate3){
            cout << "Interest Rate of " << b1.bank->getBankName() << "for " << loanType << " is lesser than that of " << b2.bank->getBankName() << " and " << b3.bank->getBankName() << endl;
        }
        else if(rate2 < rate3){
            cout << "Interest Rate of " << b2.bank->getBankName() << "for " << loanType << " is lesser than that of " << b1.bank->getBankName() << " and " << b3.bank->getBankName()  << endl;
        }
        else{
            cout << "Interest Rate of " << b3.bank->getBankName() << "for " << loanType << " is lesser than that of " << b1.bank->getBankName() << " and " << b2.bank->getBankName()  << endl;
        }
    }

    //n banks
    void compareInterestRates(vector<BankLoanPair> data, string loanType){
        if(data.empty()){
            cout << "Provide the data yo!";
            return;
        }

        double minRate = numeric_limits<double>::max(); //setting the INTEGER_MAXVALUE in C++
        vector<string> lowBanks;

        for(int i=0; i<data.size();i++){
            double rate = data[i].loan->getInterestRate(loanType);
            if(rate < minRate){
                minRate = rate;
                lowBanks.clear();
                lowBanks.push_back(data[i].bank->getBankName());
            }
            else if(rate == minRate){
                lowBanks.push_back(data[i].bank->getBankName());
            }
        }
        cout << "Banks having low interest rates for " << loanType << " are ";
        for(int i=0;i<lowBanks.size();i++){
            cout << lowBanks[i] << ", ";
        }
        cout << endl;
    }
    void printDetails(BankLoanPair data){
        data.bank->getBankInfo();
        data.loan->getAvailableLoans();
        data.loan->getInterestRate("GoldLoan");
        data.loan->getInterestRate("LandLoan");
        data.loan->getInterestRate("PersonalLoan");
        data.loan->getRequiredDocuments("GoldLoan");
        data.loan->getRequiredDocuments("LandLoan");
        data.loan->getRequiredDocuments("PersonalLoan");
    }
    void printDetails(vector<BankLoanPair> data){
        for(int i=0; i<data.size(); i++){
            data[i].bank->getBankInfo();
            data[i].loan->getAvailableLoans();
            data[i].loan->getInterestRate("GoldLoan");
            data[i].loan->getInterestRate("LandLoan");
            data[i].loan->getInterestRate("PersonalLoan");
            data[i].loan->getRequiredDocuments("GoldLoan");
            data[i].loan->getRequiredDocuments("LandLoan");
            data[i].loan->getRequiredDocuments("PersonalLoan");
            cout << "-----------------------------------------------";
        }
    }

};

int main(){

    HDFC hdfc;
    SBI sbi;
    ICICI icici;
    IndianBank indianBank;

    BankLoanPair hdfcPair = { &hdfc, &hdfc };
    BankLoanPair sbiPair = { &sbi, &sbi };
    BankLoanPair iciciPair = { &icici, &icici };
    BankLoanPair indianBankPair = { &indianBank, &indianBank };

    vector<BankLoanPair> allBanks = vector<BankLoanPair>();
    allBanks.push_back(hdfcPair);
    allBanks.push_back(sbiPair);
    allBanks.push_back(iciciPair);
    allBanks.push_back(indianBankPair);
    Broker broker;

    //single bank details
    broker.printDetails(hdfcPair);

    //multiple bank details
    broker.printDetails(allBanks);

    //compare 2 banks
    broker.compareInterestRates(hdfcPair, sbiPair, "PersonalLoan");

    //compare 3 banks
    broker.compareInterestRates(hdfcPair, sbiPair, iciciPair, "PersonalLoan");

    //compare n banks
    broker.compareInterestRates(allBanks, "PersonalLoan");

    //compare different loan types
    broker.compareInterestRates(hdfcPair, sbiPair, "GoldLoan");
    broker.compareInterestRates(sbiPair, indianBankPair, "LandLoan");
    broker.compareInterestRates(hdfcPair, iciciPair, "PersonalLoan");

    return 0;
}


//override keyword is not compatible for macOS C++ compiler so we use c++11 standard extenstion temporarily in the cmd-line while compiling.

// g++ -std=c++11 -Wall 2_BankLoadnRide.cpp -o BankLoadnRide
// ./BankLoadnRide
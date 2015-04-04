class symbol{
 public:
  symbol();
  symbol(const symbol &);
  ~symbol();
  void setData(char*, int);
  char* getName() const;
  int getBonus() const;
  void print() const;
 private:
  char* name;
  int bonus;
  bool tf;
};

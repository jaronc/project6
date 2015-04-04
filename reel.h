class reel{
 public:
  reel();
  ~reel();
  reel(const reel &);
  void setReel(symbol*);
  int spin();
  void print(int) const;
 private:
  symbol *stops;
  int payline;
};

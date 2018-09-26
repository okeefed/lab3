
class NgramList 
{
   struct Ngram
   {
      std::string ngram;
      int count;
      struct Ngram * next;
   };

   typedef struct Ngram Ngram_t;

   private:
      Ngram_t * first;
      int ngramSz;
      void insertNgram(std::string s);
      std::string getNextNgram(WordList::const_iterator start, 
                               WordList::const_iterator end);
       
   public:
      NgramList(int ngramSz, const WordList & wl);
      ~NgramList();
      void sortByCount();
      Ngram_t * quickSortByCount(Ngram_t *, Ngram_t *);
      void quickSortMain();
      Ngram_t * partition(Ngram_t *, Ngram_t *, Ngram_t **, Ngram_t **);
      Ngram_t * lastNode(Ngram_t *); 
      friend std::ostream& operator<<(std::ostream& os, const NgramList & nl);
};


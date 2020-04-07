vector
{
  vector< vector<int> > V;
  v.empty();
  v.resize(25);

  vector<int> Data(1000);
  In the example above, the data will contain 1,000 zeroes after creation.
  Remember to use parentheses, not brackets.

  If you want vector to be initialized with something else,
  write it in such manner:
  vector<string> names(20, “Unknown”);

  vector< vector<int> > Matrix(N, vector<int>(M, -1));
  Here we create a matrix of size N*M and fill it with -1.

  find()
  find(v.begin(), v.end(), 49);
  if(find(v.begin(), v.end(), 49) != v.end())

  int v1= *max_element(v.begin(), v.end());
  returns value of max element in vector;

  int i1 = min_element(v.begin(), v.end())-v.begin();
  Returns index of min element in vector

  v.insert(v.begin()+2/*index of insertion*/,5/*number to be inserted*/);

  stable_sort(v.begin(),v.end());
}


string
{
  string s = "hello";
  string
  s1 = s.substr(0, 3), // "hel"
  s2 = s.substr(1, 3), // "ell"
  s.erase(remove(s.begin(),s.end(), ' '),s.end()); //remove spaces from string


  bool val = next_permutation(s.begin(), s.end());
    if (val == false)
        cout << "No Word Possible" << endl;
    else
        cout << s << endl;
  //find lexicographically greater permutation of it. For example, 
  //lexicographically next permutation of “gfg” is “fgg” and next permutation of “acb” is “bac”.

  int x=stoi(s1); //convert string s1 to int

  
}


pair
{
  pair<int,int> P is a pair of integer values.

  pair<string, pair<int,int> > P;
  string s = P.first; // extract string
  int x = P.second.first; // extract first int
  int y = P.second.second; // extract second int
}
SETS
{
  set<int> s;
  for(int i = 1; i <= 100; i++) {
  s.insert(i); // Insert 100 elements, [1..100]
  }
  s.insert(42); // does nothing, 42 already exists in set
  for(int i = 2; i <= 100; i += 2) {
  s.erase(i); // Erase even values
  }
  int n = int(s.size()); // n will be 50
}

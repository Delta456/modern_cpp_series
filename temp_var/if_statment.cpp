int main()
{
  if (int i = 0; i > 0)
    {
      std::cout << "i is positive" << std::endl;
    }
  else if (i < 0)
    {
      std::cout << "i is negative" << std::endl;
    }
  else
    {
      std::cout << "i is zero" << std::endl;
    }
 // std::cout << i << std::endl;    // i will not be available here
}

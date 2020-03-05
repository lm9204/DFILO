/**
 * @class User
 * @author Ryan
 * @version 1.0
 */
#include <iostream>

class User
{
	private:
    	std::string user_email, user_name; 
		std::string friends;

		int unique_id;
  	public:
    	User();
		void setfrList();
		void getfrList();
		void addfr();

  	
	void User::setfrList()
	{
		//유저가 로그인할떄 가져온 데이터를 정리해서 친구를 배열로 목록화시킴-> 배열에 바인딩
		return;
	}
	void User::getfrList()
	{
		return;
	}
	void User::addfr()
	{
		//search for id
		return;
	}
  	User::User()
  	{
		  //server connect
		  //login
		  setfrList();

  	}
};
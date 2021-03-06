#include <iostream>

#include <boost/asio.hpp>
#include <glog/logging.h>

#include "endo/endo.hpp"


class Session
  : public std::enable_shared_from_this<Session> {
public:
  Session(boost::asio::ip::tcp::socket socket)
    : socket_(std::move(socket)) {
  }

  void start() {
    do_read();
  }

private:
  void do_read() {
    auto self(shared_from_this());
    socket_.async_read_some(
      boost::asio::buffer(data_, max_length),
      [this, self](boost::system::error_code ec, std::size_t length) {
        if (!ec) {
          do_write(length);
        }
      });
  }

  void do_write(std::size_t length) {
    auto self(shared_from_this());
    boost::asio::async_write(
      socket_,
      boost::asio::buffer(data_, length),
      [this, self](boost::system::error_code ec, std::size_t /*length*/) {
        if (!ec) {
          do_read();
        }
      });
  }

  boost::asio::ip::tcp::socket socket_;
  enum {
    max_length = 1024
  };
  char data_[max_length];
};

class Server {
public:
  Server(boost::asio::io_service &io_service, short port)
    : acceptor_(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)),
      socket_(io_service) {
    do_accept();
  }

private:
  void do_accept() {
    acceptor_.async_accept(
      socket_,
      [this](boost::system::error_code ec) {
        if (!ec) {
          std::make_shared<Session>(std::move(socket_))->start();
        }

        do_accept();
      });
  }

  boost::asio::ip::tcp::acceptor acceptor_;
  boost::asio::ip::tcp::socket socket_;
};

int endo_main(int argc, char *argv[]) {
  google::InitGoogleLogging(argv[0]);
  LOG(INFO) << "hi";

  try {
    // if (argc != 2) {
    //   std::cerr << "Usage: async_tcp_echo_server <port>\n";
    //   return 1;
    // }

    boost::asio::io_service io_service;

    const short port = 9999; // std::atoi(argv[1]);
    Server s(io_service, port);

    io_service.run();
  }
  catch (std::exception &e) {
    std::cerr << "Exception: " << e.what() << "\n";
  }
  return 0;
}

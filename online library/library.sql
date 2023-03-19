-- phpMyAdmin SQL Dump
-- version 4.2.11
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: Jan 13, 2017 at 06:31 AM
-- Server version: 5.6.21
-- PHP Version: 5.6.3

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `library`
--
CREATE DATABASE IF NOT EXISTS `library` DEFAULT CHARACTER SET latin1 COLLATE latin1_swedish_ci;
USE `library`;

-- --------------------------------------------------------

--
-- Table structure for table `book`
--

CREATE TABLE IF NOT EXISTS `book` (
  `b_id` varchar(20) NOT NULL,
  `b_name` varchar(30) NOT NULL,
  `publisher` varchar(30) NOT NULL,
  `author` varchar(30) NOT NULL,
  `availability` varchar(5) NOT NULL,
  `no_iss` int(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `book`
--

INSERT INTO `book` (`b_id`, `b_name`, `publisher`, `author`, `availability`, `no_iss`) VALUES
('a1', 'aca', 'ap1', 'aa1', 'yes', 15),
('a2', 'aca', 'ap1', 'aa1', 'yes', 13),
('a3', 'aca', 'ap2', 'aa2', 'yes', 1),
('d1', 'ds', 'dp1', 'da1', 'yes', 12),
('d2', 'ds', 'dp1', 'da2', 'yes', 2),
('d3', 'ds', 'dp2', 'da2', 'yes', 1),
('db1', 'dbms', 'dbp1', 'dba1', 'yes', 21),
('db2', 'dbms', 'dbp1', 'dba1', 'no', 19),
('db3', 'dbms', 'dbp2', 'dba2', 'yes', 1),
('dc1', 'dc', 'dcp1', 'dca1', 'yes', 1),
('dc2', 'dc', 'dcp2', 'dca2', 'yes', 13),
('dc3', 'dc', 'dcp2', 'dca2', 'no', 11);

-- --------------------------------------------------------

--
-- Table structure for table `borrow`
--

CREATE TABLE IF NOT EXISTS `borrow` (
`br_id` int(11) NOT NULL,
  `uid` varchar(10) NOT NULL,
  `type` varchar(10) NOT NULL,
  `bid` varchar(10) NOT NULL,
  `d_br` date NOT NULL,
  `d_ret` date NOT NULL,
  `return_d` date NOT NULL,
  `fine` int(10) NOT NULL,
  `status` varchar(20) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=55 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `borrow`
--

INSERT INTO `borrow` (`br_id`, `uid`, `type`, `bid`, `d_br`, `d_ret`, `return_d`, `fine`, `status`) VALUES
(6, 's12', 's', 'a1', '2017-01-01', '2017-01-16', '2016-12-09', 0, 'returned'),
(7, 's12', 's', 'd1', '2017-01-02', '2017-01-17', '2017-01-27', 10, 'returned'),
(10, 's90', 's', 'db1', '2016-12-01', '2016-12-16', '2016-12-09', 0, 'returned'),
(12, 's12', 's', 'dc1', '2017-01-16', '2017-01-31', '2017-02-01', 1, 'returned'),
(13, 's145', 's', 'dc2', '2017-01-04', '2017-01-19', '2016-12-14', 0, 'returned'),
(15, 'f1', 'f', 'db1', '2016-12-18', '2017-01-02', '2016-12-09', 0, 'returned'),
(16, 's145', 's', 'db1', '2016-12-05', '2016-12-20', '2016-12-09', 0, 'returned'),
(17, 'f45', 'f', 'dc2', '2016-12-03', '2016-12-18', '2016-12-14', 0, 'returned'),
(18, 'f23', 'f', 'dc2', '2016-12-06', '2016-12-21', '2016-12-14', 0, 'returned'),
(27, 'f23', 'f', 'a1', '2016-12-04', '2016-12-19', '2016-12-09', 0, 'returned'),
(28, 's145', 's', 'd2', '2016-12-03', '2016-12-18', '2016-12-08', 0, 'returned'),
(29, 's90', 's', 'd1', '2016-12-29', '2017-01-13', '2017-01-27', 10, 'returned'),
(37, 's90', 's', 'db1', '2017-01-04', '2017-01-19', '2017-01-11', 0, 'returned'),
(39, 's12', 's', 'a3', '2016-11-01', '2016-11-16', '2016-11-25', 9, 'returned'),
(40, 's12', 's', 'd3', '2016-11-10', '2016-11-25', '2016-11-14', 0, 'returned'),
(41, 's145', 's', 'db3', '2016-11-23', '2016-12-08', '2016-11-29', 0, 'returned'),
(42, 'f1', 'f', 'dc3', '2016-11-15', '2016-11-30', '2016-12-13', 13, 'returned'),
(43, 's50', 's', 'a2', '2016-10-12', '2016-10-27', '2016-12-02', 37, 'returned'),
(44, 'f45', 'f', 'dc3', '2016-09-01', '2016-09-16', '2016-09-29', 13, 'returned'),
(45, 's7', 's', 'a2', '2016-09-02', '2016-09-17', '2016-09-07', 0, 'returned'),
(46, 's7', 's', 'db2', '2016-09-08', '2016-09-23', '2016-09-30', 7, 'returned'),
(47, 's79', 's', 'd1', '2016-09-19', '2016-10-04', '2016-09-28', 0, 'returned'),
(48, 'f23', 'f', 'a2', '2016-09-09', '2016-09-24', '2016-09-16', 0, 'returned'),
(49, 's145', 's', 'a2', '2016-08-01', '2016-08-16', '2016-08-31', 15, 'returned'),
(50, 's87', 's', 'dc3', '2016-08-10', '2016-08-25', '2016-08-27', 2, 'returned'),
(51, 'f12', 'f', 'db1', '2016-09-07', '2016-09-22', '2016-09-16', 0, 'returned'),
(52, 's87', 's', 'db1', '2016-08-27', '2016-09-11', '2016-08-29', 0, 'returned'),
(53, 's87', 's', 'db2', '2017-01-10', '2017-01-25', '0000-00-00', 0, 'issued'),
(54, 'f12', 'f', 'dc3', '2017-01-06', '2017-01-21', '0000-00-00', 0, 'issued');

-- --------------------------------------------------------

--
-- Table structure for table `faculty`
--

CREATE TABLE IF NOT EXISTS `faculty` (
  `f_id` varchar(10) NOT NULL,
  `reg_no` varchar(20) NOT NULL,
  `pass` varchar(30) NOT NULL,
  `n_bk` int(10) NOT NULL,
  `fine` int(10) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `faculty`
--

INSERT INTO `faculty` (`f_id`, `reg_no`, `pass`, `n_bk`, `fine`) VALUES
('f1', '12345', '3d4', 0, 13),
('f12', '12332', '3d41', 1, 0),
('f123', '1sd', 'thy', 0, 0),
('f23', '1111', '12sw', 0, 0),
('f45', '1s2', 'asdf', 0, 13),
('fe', '145', 'dfg23', 0, 0);

-- --------------------------------------------------------

--
-- Table structure for table `librarian`
--

CREATE TABLE IF NOT EXISTS `librarian` (
  `lid` varchar(10) NOT NULL,
  `pass` varchar(30) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `librarian`
--

INSERT INTO `librarian` (`lid`, `pass`) VALUES
('l1', '1234'),
('l2', '12345'),
('l3', '123'),
('l4', '123456');

-- --------------------------------------------------------

--
-- Table structure for table `student`
--

CREATE TABLE IF NOT EXISTS `student` (
  `s_id` varchar(10) NOT NULL DEFAULT '',
  `reg_no` varchar(20) NOT NULL,
  `pass` varchar(30) NOT NULL,
  `n_bk` int(10) NOT NULL,
  `fine` int(10) DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `student`
--

INSERT INTO `student` (`s_id`, `reg_no`, `pass`, `n_bk`, `fine`) VALUES
('s12', '1145', 'sdg', 1, 9),
('s145', '156', 'tywe', 0, 15),
('s23', '1141', 'swed', 0, 0),
('s27', '21', 'asd', 0, 0),
('s30', '1146', 'hyvg', 0, 0),
('s36', '345', 'awd', 0, 0),
('s45', '1256', 'qasd', 0, 0),
('s50', '54', 'hj', 0, 37),
('s567', '5678', '1234567', 0, 0),
('s68', '5123', 'erewe', 0, 0),
('s7', '7612', 'dsf', 0, 7),
('s79', '746', 'k', 0, 0),
('s87', '8123', 'qwe', 1, 2),
('s90', '1231', 'dfg23', 0, 0),
('s9123', '12367', 'dfg231', 0, 0);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `book`
--
ALTER TABLE `book`
 ADD PRIMARY KEY (`b_id`);

--
-- Indexes for table `borrow`
--
ALTER TABLE `borrow`
 ADD PRIMARY KEY (`br_id`);

--
-- Indexes for table `faculty`
--
ALTER TABLE `faculty`
 ADD PRIMARY KEY (`f_id`);

--
-- Indexes for table `student`
--
ALTER TABLE `student`
 ADD PRIMARY KEY (`s_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `borrow`
--
ALTER TABLE `borrow`
MODIFY `br_id` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=55;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

-- phpMyAdmin SQL Dump
-- version 4.2.11
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: Jan 13, 2017 at 06:48 AM
-- Server version: 5.6.21
-- PHP Version: 5.6.3

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `rest`
--
CREATE DATABASE IF NOT EXISTS `rest` DEFAULT CHARACTER SET latin1 COLLATE latin1_swedish_ci;
USE `rest`;

-- --------------------------------------------------------

--
-- Table structure for table `customer`
--

CREATE TABLE IF NOT EXISTS `customer` (
  `c_name` varchar(20) NOT NULL,
  `c_ph` varchar(20) NOT NULL,
`c_id` int(10) NOT NULL,
  `c_ad` varchar(400) DEFAULT NULL,
  `c_pin` varchar(10) DEFAULT NULL,
  `n_or` int(5) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `customer`
--

INSERT INTO `customer` (`c_name`, `c_ph`, `c_id`, `c_ad`, `c_pin`, `n_or`) VALUES
('a', '7', 1, 'huhuoh', '1111', 3),
('b', '74', 2, 'vvv', '1113', 1),
('gh', '8171', 3, 'buhygiygiy', '1112', 0),
('ghghi', '81712', 4, 'buhygiygiysd', '1114', 1),
('shj', '45632', 5, 'biubib', '1112', 2),
('bh', '1233', 6, 'gugy', '1112', 2),
('bu', '4567', 7, NULL, '', 2),
('a8', '79', 8, NULL, '', 2);

-- --------------------------------------------------------

--
-- Table structure for table `d_boy`
--

CREATE TABLE IF NOT EXISTS `d_boy` (
  `d_name` varchar(20) NOT NULL,
`d_id` int(10) NOT NULL,
  `d_ph` varchar(20) NOT NULL,
  `a_code` varchar(10) NOT NULL,
  `availability` varchar(5) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `d_boy`
--

INSERT INTO `d_boy` (`d_name`, `d_id`, `d_ph`, `a_code`, `availability`) VALUES
('dn9', 1, '123490', '1111', 'yes'),
('dn1', 2, '1234', '1111', 'yes'),
('dn2', 3, '1324', '1112', 'no'),
('dn1', 4, '1432', '1113', 'yes'),
('dn4', 5, '13244', '1114', 'yes'),
('dn7', 6, '1234999', '1111', 'yes');

-- --------------------------------------------------------

--
-- Table structure for table `menu`
--

CREATE TABLE IF NOT EXISTS `menu` (
  `m_name` varchar(20) NOT NULL,
`m_id` int(10) NOT NULL,
  `m_type` varchar(10) NOT NULL,
  `cost` int(10) NOT NULL,
  `no_or` int(10) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `menu`
--

INSERT INTO `menu` (`m_name`, `m_id`, `m_type`, `cost`, `no_or`) VALUES
('f1', 1, 'f', 100, 15),
('f2', 2, 'f', 200, 30),
('b1', 3, 'b', 100, 2),
('b2', 4, 'b', 75, 3),
('f3', 5, 'f', 300, 25),
('f4', 6, 'f', 350, 40),
('f5', 7, 'f', 350, 5),
('b4', 8, 'b', 150, 35),
('b3', 9, 'b', 95, 1);

-- --------------------------------------------------------

--
-- Table structure for table `of_order`
--

CREATE TABLE IF NOT EXISTS `of_order` (
`oid` int(20) NOT NULL,
  `cid` int(10) NOT NULL,
  `bill` int(5) NOT NULL,
  `or_dt` date NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `of_order`
--

INSERT INTO `of_order` (`oid`, `cid`, `bill`, `or_dt`) VALUES
(1, 1, 475, '2017-01-01'),
(2, 1, 475, '2017-01-02'),
(3, 8, 175, '2017-01-02'),
(4, 8, 1250, '2016-12-08'),
(5, 6, 985, '2016-12-25'),
(6, 7, 560, '2016-11-01'),
(7, 5, 795, '2016-11-22'),
(8, 2, 1236, '2016-11-08'),
(9, 3, 2506, '2016-11-17'),
(10, 4, 783, '2016-11-25'),
(11, 5, 360, '2016-11-29');

-- --------------------------------------------------------

--
-- Table structure for table `on_order`
--

CREATE TABLE IF NOT EXISTS `on_order` (
`oid` int(20) NOT NULL,
  `cid` int(10) NOT NULL,
  `did` int(10) NOT NULL,
  `bill` int(5) NOT NULL,
  `or_dt` date NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `on_order`
--

INSERT INTO `on_order` (`oid`, `cid`, `did`, `bill`, `or_dt`) VALUES
(1, 1, 1, 650, '2017-01-01'),
(2, 2, 4, 935, '2016-12-25'),
(3, 4, 5, 1956, '2016-11-24');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `customer`
--
ALTER TABLE `customer`
 ADD PRIMARY KEY (`c_id`);

--
-- Indexes for table `d_boy`
--
ALTER TABLE `d_boy`
 ADD PRIMARY KEY (`d_id`);

--
-- Indexes for table `menu`
--
ALTER TABLE `menu`
 ADD PRIMARY KEY (`m_id`), ADD UNIQUE KEY `m_name` (`m_name`);

--
-- Indexes for table `of_order`
--
ALTER TABLE `of_order`
 ADD PRIMARY KEY (`oid`);

--
-- Indexes for table `on_order`
--
ALTER TABLE `on_order`
 ADD PRIMARY KEY (`oid`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `customer`
--
ALTER TABLE `customer`
MODIFY `c_id` int(10) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=9;
--
-- AUTO_INCREMENT for table `d_boy`
--
ALTER TABLE `d_boy`
MODIFY `d_id` int(10) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=7;
--
-- AUTO_INCREMENT for table `menu`
--
ALTER TABLE `menu`
MODIFY `m_id` int(10) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=10;
--
-- AUTO_INCREMENT for table `of_order`
--
ALTER TABLE `of_order`
MODIFY `oid` int(20) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=12;
--
-- AUTO_INCREMENT for table `on_order`
--
ALTER TABLE `on_order`
MODIFY `oid` int(20) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=4;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

-- MySQL dump 8.21
--
-- Host: localhost    Database: mycms
---------------------------------------------------------
-- Server version	3.23.48-Max-log
DROP DATABASE IF EXISTS mycms;
CREATE DATABASE mycms;
USE mycms;


--
-- Table structure for table 'content'
--

CREATE TABLE content (
  content_id int(11) NOT NULL auto_increment,
  site_id int(11) default NULL,
  page_id int(11) default NULL,
  ref_id int(11) default NULL,
  title varchar(100) default NULL,
  title_font_size int(11) default NULL,
  title_font_face varchar(100) default NULL,
  title_align varchar(6) default NULL,
  body blob,
  body_font_size int(11) default NULL,
  body_font_face varchar(100) default NULL,
  body_align varchar(6) default NULL,
  body_color_bg int(11) default 0,
  body_color_fg int(11) default 0,
  body_image varchar(100) default NULL,
  body_link varchar(100) default NULL,
  body_vlink varchar(100) default NULL,
  body_alink varchar(100) default NULL,
  content_image varchar(150) default NULL,
  content_image_align varchar(6) default NULL,
  PRIMARY KEY  (content_id)
) TYPE=MyISAM;

--
-- Dumping data for table 'content'
--


INSERT INTO content VALUES (1,1,1,1,'Content Title',1,'times','left','this is a test',5,'times','left',0,16777215,'images/watch.jpg',10092543,10079487,10092543,'','left');
INSERT INTO content VALUES (2,1,1,2,'Content Title',5,'serif','center','this is a test 2',2,'times','left',0,16777215,'images/watch.jpg',10092543,10079487,10092543,'','center');
INSERT INTO content VALUES (3,1,1,3,'Content Title',1,'serif','left','this is a test 3',3,'times','center',0,16777215,'images/watch.jpg',10092543,10079487,10092543,'','center');

INSERT INTO content VALUES (4,1,2,1,'2Content Title',1,'serif','left','this is a test 4',3,'times','center',0,16777215,'images/watch.jpg',10092543,10079487,10092543,'','center');
INSERT INTO content VALUES (5,1,2,2,'2Content Title',1,'serif','left','this is a test 5',3,'times','center',0,16777215,'images/watch.jpg',10092543,10079487,10092543,'','center');

--
-- Table structure for table 'host'
--

CREATE TABLE host (
  host_id int(11) NOT NULL auto_increment,
  sites int(11) default NULL,
  program_txt blob,
  url blob,
  PRIMARY KEY  (host_id)
) TYPE=MyISAM;

--
-- Dumping data for table 'host'
--



--
-- Table structure for table 'page'
--

CREATE TABLE page (
  page_id int(11) NOT NULL auto_increment,
  site_id int(11) default NULL,
  ref_id int(11) default NULL,
  parent_id int(11) default NULL,
  type varchar(50) NOT NULL default '',
  page_title varchar(100) default NULL,
  page_heading varchar(100) default NULL,
  title_font_size int(11) default NULL,
  title_font_face varchar(100) default NULL,
  title_align varchar(6) default NULL,
  last_updated int(24) default NULL,
  email_contact varchar(100) default NULL,
  telephone_contact varchar(20) default NULL,
  code int(24) NOT NULL default '0',
  PRIMARY KEY  (page_id)
) TYPE=MyISAM;

--
-- Dumping data for table 'page'
--


INSERT INTO page VALUES (1,1,0,0,'type','My Home Page Title','My Page Heading',20,'times','center',1048014082,'parasyte@thing.stuff','7739350834',0);
INSERT INTO page VALUES (2,1,1,0,'type','My Page Title 2','My Page Heading',20,'times','center',1048014082,'parasyte@thing.stuff','7739350834',0);

--
-- Table structure for table 'site'
--

CREATE TABLE site (
  site_id int(11) NOT NULL auto_increment,
  host_id int(11) default NULL,
  password varchar(8) NOT NULL default '',
  name_contact varchar(100) default NULL,
  alias varchar(100) NOT NULL default '',
  homepage_id int(11) default NULL,
  PRIMARY KEY  (site_id)
) TYPE=MyISAM;

--
-- Dumping data for table 'site'
--


INSERT INTO site VALUES (1,1,'eertwfld','karl','mysite',1);


/*
  Usage: cat main.c | mysql -uroot -proot
*/
CREATE DATABASE IF NOT EXISTS `test`;
USE `test`;
CREATE TABLE IF NOT EXISTS `users` (
`id` int(11) NOT NULL AUTO_INCREMENT,
`name` varchar(50) NOT NULL DEFAULT '',
`gender` varchar(10) NOT NULL DEFAULT '',
`birth_day` int(11) NOT NULL DEFAULT '0', /*19920117*/
`work_day` int(11) NOT NULL DEFAULT '0', /*20110111*/
`xl` varchar(10) NOT NULL DEFAULT '', /*学历*/
`zw` varchar(10) NOT NULL DEFAULT '', /*职务*/
`addr` varchar(255) not null default '',
`phone` varchar(50) NOT NULL DEFAULT '',
PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

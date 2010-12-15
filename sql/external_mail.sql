CREATE TABLE IF NOT EXISTS `mail_external` (
  `id` bigint(20) unsigned NOT NULL auto_increment,
  `receiver` bigint(20) unsigned NOT NULL,
  `subject` varchar(200) default 'Support Message',
  `message` varchar(500) default 'Support Message',
  `money` bigint(20) unsigned NOT NULL default '0',
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM  DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `mail_external_items` (
  `id` int(10) unsigned NOT NULL auto_increment,
  `mail_id` int(10) unsigned NOT NULL,
  `item` int(11) NOT NULL,
  `count` int(11) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1;
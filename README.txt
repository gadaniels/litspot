README.txt for litspot
---------------------------

CONTENTS OF THIS FILE
---------------------

 * Introduction
 * Requirements
 * API Usage


Introduction
--------------
This module is designed to facilitate interaction between Drupal and the Legal Innovation Lab's SPOT classifier (https://spot.suffolklitlab.org/).

It does not have an interface beyond configuration.  It is designed to be integrated with custom modules.  See the ilao_suffolk example.

Requirements
-------------
To use the SPOT classifier, you must first obtain an API key, which needs to be added to the configuration.

API Usage
-----------

 * litspot_api_entities_nested accepts a text string and returns the nested entities from the Spot classifier.
 * litspot_api_entities_terminal accepts a text string and returns the terminal entities from the Spot classifier.
 * litspot_entities_get_query_id accepts a resulting API result and returns the query ID if it exists.
 * litspot_api_get_taxonomy gets the Spot taxonomy
 * litspot_api_post_actions accepts a required query_id and data (in favor, against, clear) to the Actions API
 * litspot_api_post_opinions accpets a required query_id and data (present, not_present, clear) to the Opinions API

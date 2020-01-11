<?php
/**
 * Created by PhpStorm.
 * User: gdaniels
 * Date: 12/3/19
 * Time: 8:52 AM
 */

function ilao_suffolk_data_sample_form($form, &$form_state) {
  $form['header'] = array(
    '#markup' => t('Enter the text you want the classifier to analyze'),
    '#type' => 'markup',
  );
  $form['suffolk_text'] = array(
    '#type' => 'textarea',
    '#title' => t('Text to classify'),
  );
  $form['suffolk_type'] = array (
    '#type' => 'select',
    '#title' => t('Which method do you want to use'),
    '#options' => array (
      'nested' => t('Nested entities'),
      'terminal' => t('Terminal entities')
    ),
  );
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#submit' => array('ilao_suffolk_data_sample_submit'),
  );

  return $form;


}

function ilao_suffolk_data_sample_submit ($form, &$form_state) {
  if ($form_state['values']['suffolk_type'] == 'nested') {

  $_SESSION['suffolk']['data'] = litspot_api_entities_nested($form_state['values']['suffolk_text']);
  }
  else {
    $_SESSION['suffolk']['data'] = litspot_api_entities_terminal($form_state['values']['suffolk_text']);
  }
  $_SESSION['suffolk']['query'] = $form_state['values']['suffolk_text'];
  $form_state['redirect'] = array ('ilao_suffolk_post');

}
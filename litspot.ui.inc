<?php
/**
 * Created by PhpStorm.
 * User: gdaniels
 * Date: 9/9/19
 * Time: 2:59 PM
 */

function litspot_config_form($form, &$form_state) {
  $form['header'] = array(
    '#markup' => t('Use this form to configure your API settings to the Suffolk LIT Spot Classifier'),
    '#type' => 'markup',
  );
  $form['litspot_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t('API Key'),
    '#default_value' => variable_get('litspot_api_key'),
  );
  $form['litspot_url'] = array(
    '#type' => 'textfield',
    '#title' => t('URL for Suffolk classifier server'),
    '#description' => t('Include the https and version but not the API function.  For example https://spot.suffolklitlab.org/v0/'),
    '#default_value' => variable_get('litspot_url') ? variable_get('litspot_url') : 'https://spot.suffolklitlab.org/v0/',
  );
  $form['litspot_save_text'] = array(
    '#type' => 'textfield',
    '#title' => t("Allow classifier to save text"),
    '#description' => t("Enter 0 or 1"),
    '#default_value' => variable_get('litspot_save_text') ? variable_get('litspot_save_text') : '1',
  );
  $form['litspot_cutoff_lower'] = array(
    '#type' => 'textfield',
    '#title' => t("Cutoff lower"),
    '#description' => t("Enter a value between 0 and 1.  This is the lower bound of uncertainty"),
    '#default_value' => variable_get('litspot_cutoff_lower') ? variable_get('litspot_cutoff_lower') : '0',
  );
  $form['litspot_cutoff_upper'] = array(
    '#type' => 'textfield',
    '#title' => t("Cutoff upper"),
    '#description' => t("Enter a value between 0 and 1.  This is the upper bound of uncertainty"),
    '#default_value' => variable_get('litspot_cutoff_upper') ? variable_get('litspot_cutoff_upper') : '.5',
  );
  $form['litspot_cutoff_pred'] = array(
    '#type' => 'textfield',
    '#title' => t("Prediction cutoff"),
    '#description' => t("Enter a value between 0 and 1.  The prediction must exceed this to be included in results"),
    '#default_value' => variable_get('litspot_cutoff_pred') ? variable_get('litspot_cutoff_pred') : '.5',
  );
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#submit' => array('litspot_config_submit'),
  );

  return $form;
}

function litspot_config_form_validate($form, &$form_state) {
  if (empty($form_state['values']['litspot_api_key'])) {
    form_set_error('litspot_api_key', t('API key is required'));
  }
  if (empty($form_state['values']['litspot_url'])) {
    form_set_error('litspot_url', t('URL is required'));
  }
  if (is_numeric($form_state['values']['litspot_cutoff_lower']) === FALSE) {

    form_set_error('litspot_cutoff_lower', t('Cutoff lower value must be a number'));
  }
  else {
    if ($form_state['values']['litspot_cutoff_lower'] < 0 || $form_state['values']['litspot_cutoff_lower'] > 1) {
      form_set_error('litspot_cutoff_lower', t('Cutoff lower value must be between 0 an 1'));
    }
  }
  if (is_numeric($form_state['values']['litspot_cutoff_upper']) === FALSE) {

    form_set_error('litspot_cutoff_upper', t('Cutoff upper value must be a number'));
  }
  else {
    if ($form_state['values']['litspot_cutoff_upper'] < 0 || $form_state['values']['litspot_cutoff_upper'] > 1) {
      form_set_error('litspot_cutoff_upper', t('Cutoff upper value must be between 0 an 1'));
    }
  }
  if (is_numeric($form_state['values']['litspot_cutoff_pred']) === FALSE) {

    form_set_error('litspot_cutoff_pred', t('Prediction cutoff must be a number'));
  }
  else {
    if ($form_state['values']['litspot_cutoff_pred'] < 0 || $form_state['values']['litspot_cutoff_pred'] > 1) {
      form_set_error('litspot_cutoff_pred', t('Prediction cutoff value must be between 0 an 1'));
    }
  }
}

function litspot_config_submit($form, &$form_state) {
  variable_set('litspot_api_key', $form_state['values']['litspot_api_key']);
  variable_set('litspot_cutoff_lower', $form_state['values']['litspot_cutoff_lower']);
  variable_set('litspot_cutoff_upper', $form_state['values']['litspot_cutoff_upper']);
  variable_set('litspot_cutoff_pred', $form_state['values']['litspot_cutoff_pred']);
  variable_set('litspot_url', $form_state['values']['litspot_url']);
  variable_set('litspot_save_text', $form_state['values']['litspot_save_text']);
  drupal_set_message(t('Form saved'));
}


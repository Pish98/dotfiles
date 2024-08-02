vim.keymap.set("n", "<S-F10>", function ()
  local languages = {
    rave = "rave $p -o /tmp/$n && /tmp/$n && rm /tmp/$n",
    javascript = "node $p",
    java = "java $p",
    php = "php $p",
    python = "python3 $p",
    c = "cc $p -o /tmp/$n && /tmp/$n && rm /tmp/$n",
    cpp = "c++ $p -o /tmp/$n && /tmp/$n && rm /tmp/$n",
    lua = "lua $p",
    sql = "mariadb --execute=\\\"source $po\\\"",
    sh = "sh $p"
  };

  local fn = vim.api.nvim_buf_get_name(0);
  local nn = fn:match("^.+/(.+)$");
  local ext = vim.fn.expand('%:e');
  local ft = vim.bo.filetype;

  if not (languages[ext] or languages[ft]) then
    vim.cmd("echo 'Cannot run this file'")
    return
  end;

  local cmd = (languages[ext] or languages[ft])
    :gsub("$po", fn)
    :gsub("$no", nn)
    :gsub("$n", "'" .. nn .. "'")
    :gsub("$p", "'" .. fn .. "'")

  vim.cmd("w")
  vim.cmd("horizontal botright split term://" .. cmd .. " && sleep 0.1")
  vim.cmd("norm G");
end);
